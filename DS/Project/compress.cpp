#include "library.cpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./compress <input_file> <output_file.huff>\n";
        return 1;
    }

    ifstream input(argv[1], ios::binary);
    if (!input.is_open()) {
        cerr << "Error: Cannot open input file " << argv[1] << "\n";
        return 1;
    }

    ofstream output(argv[2], ios::binary);
    if (!output.is_open()) {
        cerr << "Error: Cannot create output file " << argv[2] << "\n";
        return 1;
    }

    uint64_t freq[256] = {};
    vector<char> buffer(IO_BUFFER_SIZE);
    uint64_t totalOriginalBytes = 0;

    // Pass 1: Count byte frequencies
    while (input.read(buffer.data(), IO_BUFFER_SIZE) || input.gcount() > 0) {
        streamsize bytesRead = input.gcount();
        totalOriginalBytes += bytesRead;
        for (streamsize i = 0; i < bytesRead; i++) {
            freq[(unsigned char)buffer[i]]++;
        }
    }

    // Write header: magic bytes + original file size
    output.write(HUFF_MAGIC, sizeof(HUFF_MAGIC));
    output.write(reinterpret_cast<const char*>(&totalOriginalBytes), sizeof(totalOriginalBytes));

    if (totalOriginalBytes == 0) {
        cout << "Compressed empty file: " << argv[1] << " -> " << argv[2] << "\n";
        return 0;
    }

    // Build Huffman tree & generate codes
    Node* root = buildTree(freq);
    if (!root) {
        cerr << "Error: Failed to build Huffman tree\n";
        return 1;
    }

    string codes[256];
    makeCodes(root, codes);

    // Save tree structure to output
    BitWriter bitWriter(output);
    serializeTree(root, bitWriter);

    // Pass 2: Encode file content
    input.clear();
    input.seekg(0, ios::beg);

    while (input.read(buffer.data(), IO_BUFFER_SIZE) || input.gcount() > 0) {
        streamsize bytesRead = input.gcount();
        for (streamsize i = 0; i < bytesRead; i++) {
            bitWriter.writeCode(codes[(unsigned char)buffer[i]]);
        }
    }

    bitWriter.flush();
    deleteTree(root);
    input.close();
    output.close();

    // Get compressed size
    ifstream checkOut(argv[2], ios::binary | ios::ate);
    streampos compressedBytes = checkOut.tellg();
    checkOut.close();

    cout << "Compressed " << argv[1] << " -> " << argv[2] << " ("
         << totalOriginalBytes << " -> " << compressedBytes << " bytes)\n";

    return 0;
}
