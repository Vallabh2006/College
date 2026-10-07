#include "library.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./compress <input_file> <output_file.huff>\n";
        return 1;
    }

    ifstream input(argv[1], ios::binary);
    ofstream output(argv[2], ios::binary);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files.\n";
        return 1;
    }

    int freq[256] = {0};
    int totalBytes = 0;
    char ch;

    while (input.get(ch)) {
        freq[ch & 255]++;
        totalBytes++;
    }

    output.write((char*)&totalBytes, sizeof(int));
    output.write((char*)freq, sizeof(freq));

    if (totalBytes == 0) {
        cout << "Compressed empty file.\n";
        return 0;
    }

    Node* root = buildTree(freq);
    string codes[256];
    generateCodes(root, codes);

    input.clear();
    input.seekg(0, ios::beg);
    BitWriter bw(output);

    while (input.get(ch)) {
        bw.writeCode(codes[ch & 255]);
    }
    bw.flush();

    cout << "Compressed " << argv[1] << " -> " << argv[2] << " (" << totalBytes << " bytes)\n";
    return 0;
}
