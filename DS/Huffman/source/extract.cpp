#include "library.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./extract <input_file.huff> <output_file>\n";
        return 1;
    }

    ifstream input(argv[1], ios::binary);
    ofstream output(argv[2], ios::binary);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files.\n";
        return 1;
    }

    int totalBytes = 0;
    int freq[256] = {0};

    input.read((char*)&totalBytes, sizeof(int));
    input.read((char*)freq, sizeof(freq));

    if (totalBytes == 0) {
        cout << "Extracted empty file.\n";
        return 0;
    }

    Node* root = buildTree(freq);
    Node* curr = root;

    BitReader br(input);
    int decodedBytes = 0;

    while (decodedBytes < totalBytes) {
        int bit = br.readBit();
        if (bit == -1) break;

        curr = (bit == 0) ? curr->left : curr->right;

        if (!curr->left && !curr->right) {
            output.put((char)curr->ch);
            decodedBytes++;
            curr = root;
        }
    }

    cout << "Extracted " << argv[1] << " -> " << argv[2] << " (" << decodedBytes << " bytes)\n";
    return 0;
}
