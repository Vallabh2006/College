# Huffman File Compressor

A lossless file compressor and extractor based on **Huffman Coding** and **Binary Trees** implemented in C++. It works with any file type (`.txt`, `.pdf`, `.png`, `.jpg`, `.bin`, etc.).

---

## 📁 Project Structure

```text
.
├── library.cpp     # Huffman tree data structure, bit-level reader/writer, serialization
├── compress.cpp    # Compresses any input file to a .huff file
├── extract.cpp     # Decompresses a .huff file back to the original file
└── README.md       # Project documentation and usage guide
```

---

## ⚙️ How It Works

1. **Frequency Count**: Reads the input file in 64 KB chunks and calculates the frequency of each byte (0 to 255).
2. **Build Huffman Tree**: Constructs a binary tree using a priority queue (min-heap) to give shorter binary codes to more frequent bytes.
3. **Save Tree Structure**: Serializes the tree into the file header using pre-order traversal (`0` for internal node, `1` followed by 8-bit character for leaf node).
4. **Encode & Write Bits**: Replaces each byte with its prefix code and writes packed bits into the output `.huff` file.
5. **Lossless Extraction**: Rebuilds the Huffman tree from the header and decodes bits back into the exact original bytes.

---

## 🚀 Compilation

Compile both programs using `g++`:

```bash
g++ -O2 compress.cpp -o compress
g++ -O2 extract.cpp -o extract
```

---

## 💻 Usage

### 1. Compress a File
```bash
./compress <input_file> <output_file.huff>
```
*Example:*
```bash
./compress document.txt document.huff
```

### 2. Extract / Decompress a File
```bash
./extract <input_file.huff> <output_file>
```
*Example:*
```bash
./extract document.huff restored.txt
```

### 3. Verify Lossless Integrity
```bash
cmp document.txt restored.txt && echo "Files are identical!"
```
