#ifndef LIBRARY_CPP
#define LIBRARY_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <cstdint>
#include <cstring>

using namespace std;

const char HUFF_MAGIC[4] = {'H', 'U', 'F', '1'};
const size_t IO_BUFFER_SIZE = 65536;

// Huffman Tree Node
struct Node {
    unsigned char ch;
    uint64_t freq;
    Node *left, *right;

    Node(unsigned char c, uint64_t f = 0) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch(0), freq((l ? l->freq : 0) + (r ? r->freq : 0)), left(l), right(r) {}

    bool leaf() const {
        return !left && !right;
    }
};

// Comparator for Min-Heap
struct Compare {
    bool operator()(const Node* a, const Node* b) const {
        return a->freq > b->freq;
    }
};

// Bit-level Writer with buffer
class BitWriter {
private:
    ofstream& out;
    uint8_t bitBuffer;
    int bitCount;
    vector<char> byteBuffer;

public:
    BitWriter(ofstream& os) : out(os), bitBuffer(0), bitCount(0) {
        byteBuffer.reserve(IO_BUFFER_SIZE);
    }

    void writeBit(int bit) {
        bitBuffer = (bitBuffer << 1) | (bit & 1);
        bitCount++;
        if (bitCount == 8) {
            byteBuffer.push_back((char)bitBuffer);
            if (byteBuffer.size() >= IO_BUFFER_SIZE) {
                out.write(byteBuffer.data(), byteBuffer.size());
                byteBuffer.clear();
            }
            bitBuffer = 0;
            bitCount = 0;
        }
    }

    void writeByte(uint8_t b) {
        for (int i = 7; i >= 0; i--) {
            writeBit((b >> i) & 1);
        }
    }

    void writeCode(const string& code) {
        for (char c : code) {
            writeBit(c - '0');
        }
    }

    void flush() {
        if (bitCount > 0) {
            bitBuffer <<= (8 - bitCount);
            byteBuffer.push_back((char)bitBuffer);
            bitBuffer = 0;
            bitCount = 0;
        }
        if (!byteBuffer.empty()) {
            out.write(byteBuffer.data(), byteBuffer.size());
            byteBuffer.clear();
        }
    }
};

// Bit-level Reader with buffer
class BitReader {
private:
    ifstream& in;
    uint8_t bitBuffer;
    int bitPos;
    vector<char> byteBuffer;
    size_t bytePos;
    size_t bytesLoaded;

public:
    BitReader(ifstream& is) : in(is), bitBuffer(0), bitPos(-1), byteBuffer(IO_BUFFER_SIZE), bytePos(0), bytesLoaded(0) {}

    int readBit() {
        if (bitPos < 0) {
            if (bytePos >= bytesLoaded) {
                in.read(byteBuffer.data(), IO_BUFFER_SIZE);
                bytesLoaded = in.gcount();
                bytePos = 0;
                if (bytesLoaded == 0) return -1;
            }
            bitBuffer = (uint8_t)byteBuffer[bytePos++];
            bitPos = 7;
        }
        return (bitBuffer >> bitPos--) & 1;
    }

    int readByte() {
        int val = 0;
        for (int i = 0; i < 8; i++) {
            int b = readBit();
            if (b == -1) return -1;
            val = (val << 1) | b;
        }
        return val;
    }
};

// Build Huffman Tree from frequencies
inline Node* buildTree(const uint64_t freq[256]) {
    priority_queue<Node*, vector<Node*>, Compare> q;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            q.push(new Node((unsigned char)i, freq[i]));
        }
    }

    if (q.empty()) return nullptr;

    if (q.size() == 1) {
        Node* temp = q.top();
        q.pop();
        return new Node(temp, new Node((unsigned char)0, 0));
    }

    while (q.size() > 1) {
        Node* a = q.top(); q.pop();
        Node* b = q.top(); q.pop();
        q.push(new Node(a, b));
    }

    return q.top();
}

// Serialize Huffman Tree to bitstream
inline void serializeTree(const Node* root, BitWriter& writer) {
    if (!root) return;
    if (root->leaf()) {
        writer.writeBit(1);
        writer.writeByte(root->ch);
    } else {
        writer.writeBit(0);
        serializeTree(root->left, writer);
        serializeTree(root->right, writer);
    }
}

// Deserialize Huffman Tree from bitstream
inline Node* deserializeTree(BitReader& reader) {
    int bit = reader.readBit();
    if (bit == -1) return nullptr;

    if (bit == 1) {
        int ch = reader.readByte();
        if (ch == -1) return nullptr;
        return new Node((unsigned char)ch, 0);
    } else {
        Node* left = deserializeTree(reader);
        Node* right = deserializeTree(reader);
        return new Node(left, right);
    }
}

// Generate Huffman prefix codes
inline void makeCodes(const Node* root, string codes[256], string path = "") {
    if (!root) return;
    if (root->leaf()) {
        codes[root->ch] = path.empty() ? "0" : path;
        return;
    }
    makeCodes(root->left, codes, path + "0");
    makeCodes(root->right, codes, path + "1");
}

// Free tree memory
inline void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

#endif
