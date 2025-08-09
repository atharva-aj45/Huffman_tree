#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for min-heap
struct comp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Min-heap
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char,string> &huffmanCode) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        // Handle single-character special case
        if (code == "") code = "0";
        huffmanCode[root->ch] = code;
        return;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Decode Huffman string
string decodeText(Node* root, const string &encodedStr) {
    string decoded = "";
    Node* current = root;
    for (char bit : encodedStr) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        // Leaf node
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

int main() {
    string text;
    cout << "Enter text to encode: ";
    getline(cin,text);

    // Frequency map
    unordered_map<char, int> freq;
    int n=text.length();
    for (int i=0;i<n;i++)
        freq[text[i]]++;

    // Min-heap(priority queue)
    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto it : freq) {
        Node* temp = new Node(it.first, it.second);
        pq.push(temp);
    }

    // Building Tree
    while(pq.size()>1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }
    Node* root =pq.top();

    // Generateing Huffman Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for(auto it : huffmanCode)
        cout << it.first << ": " << it.second << "\n";

    // Encodeing text
    string encoded = "";
    for (char ch : text)
        encoded += huffmanCode[ch];

    cout << "\nEncoded Text: " << encoded << "\n";

    // Decodeing text
    string decoded = decodeText(root, encoded);
    cout << "\nDecoded Text: " << decoded << "\n";

    // Compression stats
    int bits_original = text.length() * 8;
    int bits_compressed = encoded.length();
    double ration = ((double)bits_compressed / bits_original)*100;
    cout<<"\nOriginal Size: "<<bits_original << " bits";
    cout<<"\nCompressed Size: "<< bits_compressed << " bits";
    cout<<"\nCompression Ratio: "<<ration << "%\n";

    return 0;
}

