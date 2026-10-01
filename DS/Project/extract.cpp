#include "library.cpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./extract <input_file.huff> <output_file>\n";
        return 1;
    }

    ifstream input(argv[1], ios::binary);
    if (!input.is_open()) {
        cerr << "Error: Cannot open compressed file " << argv[1] << "\n";
        return 1;
    }

    // Validate header magic
    char magic[4];
    input.read(magic, 4);
    if (input.gcount() < 4 || memcmp(magic, HUFF_MAGIC, 4) != 0) {
        cerr << "Error: Invalid or corrupted .huff file\n";
        return 1;
    }

    // Read original size
    uint64_t totalOriginalBytes = 0;
    input.read(reinterpret_cast<char*>(&totalOriginalBytes), sizeof(totalOriginalBytes));
    if (input.gcount() < (streamsize)sizeof(totalOriginalBytes)) {
        cerr << "Error: Corrupted file header\n";
        return 1;
    }

    ofstream output(argv[2], ios::binary);
    if (!output.is_open()) {
        cerr << "Error: Cannot create output file " << argv[2] << "\n";
        return 1;
    }

    if (totalOriginalBytes == 0) {
        cout << "Extracted empty file: " << argv[1] << " -> " << argv[2] << "\n";
        return 0;
    }

    // Reconstruct Huffman tree
    BitReader bitReader(input);
    Node* root = deserializeTree(bitReader);
    if (!root) {
        cerr << "Error: Failed to reconstruct Huffman tree\n";
        return 1;
    }

    // Decode bitstream
    vector<char> outBuffer(IO_BUFFER_SIZE);
    size_t outBufPos = 0;
    uint64_t decodedBytes = 0;
    Node* current = root;

    while (decodedBytes < totalOriginalBytes) {
        int bit = bitReader.readBit();
        if (bit == -1) {
            cerr << "Error: Unexpected end of file\n";
            break;
        }

        current = (bit == 0) ? current->left : current->right;
        if (!current) {
            cerr << "Error: Corrupted Huffman tree path\n";
            deleteTree(root);
            return 1;
        }

        if (current->leaf()) {
            outBuffer[outBufPos++] = (char)current->ch;
            decodedBytes++;

            if (outBufPos >= IO_BUFFER_SIZE) {
                output.write(outBuffer.data(), outBufPos);
                outBufPos = 0;
            }
            current = root;
        }
    }

    if (outBufPos > 0) {
        output.write(outBuffer.data(), outBufPos);
    }

    deleteTree(root);
    input.close();
    output.close();

    cout << "Extracted " << argv[1] << " -> " << argv[2] << " ("
         << decodedBytes << " bytes)\n";

    return 0;
}
