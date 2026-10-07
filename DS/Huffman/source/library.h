#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int ch;
    int freq;
    Node *left;
    Node *right;

    Node(int c, int f, Node* l = nullptr, Node* r = nullptr)
        : ch(c), freq(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

struct BitWriter {
    ofstream& out;
    int buffer;
    int count;

    BitWriter(ofstream& os) : out(os), buffer(0), count(0) {}

    void writeBit(int bit) {
        buffer = (buffer << 1) | (bit & 1);
        count++;
        if (count == 8) {
            out.put((char)buffer);
            buffer = 0;
            count = 0;
        }
    }

    void writeCode(const string& code) {
        for (char c : code) {
            writeBit(c - '0');
        }
    }

    void flush() {
        if (count > 0) {
            buffer <<= (8 - count);
            out.put((char)buffer);
            buffer = 0;
            count = 0;
        }
    }
};

struct BitReader {
    ifstream& in;
    int buffer;
    int count;

    BitReader(ifstream& is) : in(is), buffer(0), count(0) {}

    int readBit() {
        if (count == 0) {
            char c;
            if (!in.get(c)) return -1;
            buffer = c & 255;
            count = 8;
        }
        count--;
        return (buffer >> count) & 1;
    }
};

inline Node* buildTree(const int freq[256]) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(new Node(i, freq[i]));
        }
    }

    if (pq.empty()) return nullptr;

    if (pq.size() == 1) {
        Node* only = pq.top(); pq.pop();
        return new Node(0, only->freq, only, nullptr);
    }

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        pq.push(new Node(0, a->freq + b->freq, a, b));
    }

    return pq.top();
}

inline void generateCodes(Node* root, string codes[256], string code = "") {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = code.empty() ? "0" : code;
        return;
    }
    generateCodes(root->left, codes, code + "0");
    generateCodes(root->right, codes, code + "1");
}

#endif
