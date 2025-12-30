#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Non-Recursive Function
Node* buildHuffmanTree(unordered_map<char, int>& freq) {
    // Define minHeap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Populate minHeap
    for (auto pair: freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }
    // Build Huffman Tree
    while (minHeap.size() > 1){
        // Select the two elements from the minHeap
        // having least frequencies
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();
        
        // Generate non-leaf node
        // Generated node chracter -> '$'
        Node* internal = new Node('$', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        
        // Push generated node to tree
        minHeap.push(internal);
    }
    return minHeap.top();
}

// Recursive Function
// Tree is traversed bottom-to-up
void storeCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->data] = code;
        return;
    } // If at root, character code is complete
    storeCodes(root->left, code+"0", codes);        // If left edge, append 0 to character code
    storeCodes(root->right, code+"1", codes);       // If right edge, append 1 to character code
}

int main() {
    // 1. Get text input
    string text;
    cout << "Enter text to encode: ";
    getline(cin, text);

    // 2. Calculate frequencies
    cout << endl << "Calculating frequencies..." << endl;
    unordered_map<char, int> freq;
    for (char c: text) {
        freq[c]++;
    }
    // 3. Build the tree
    cout << "Building Huffman tree..." << endl;
    Node* root = buildHuffmanTree(freq);

    // 4. Generate the huffman codes
    cout << "Generating Huffman encoding table..." << endl;
    unordered_map<char, string> codes;
    storeCodes(root, "", codes);
    cout << endl;

    // 4. Print out encoding table
    cout << "Huffman Encoding Table" << endl;
    for (auto pair: codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // 5. Print out compression results
    int originalBits = 8*text.length();
    int compressedBits = 0;
    string compressedMessage = "";

    for (char c: text) {
        compressedBits += codes[c].length();
        compressedMessage += codes[c];
    } // Calculating new length of compressed message

    cout << "Compressed Message: " << compressedMessage << endl << endl;
    cout << "No. of bits required to store original message: " << originalBits << endl;
    cout << "No. of bits required to store compressed version: " << compressedBits << endl;
    cout << "Size reduction: " << (originalBits-compressedBits)*100/originalBits << "%" << endl;

    return 0;
}






