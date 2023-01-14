#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root)
        return;
    if (root->ch != '$') {
        huffmanCode[root->ch] = str;
    }
    printCode(root->left, str + "0", huffmanCode);
    printCode(root->right, str + "1", huffmanCode);
}

void HuffmanCodes(string S, int f[], int n) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(new Node{ S[i], f[i], nullptr, nullptr });
    while (minHeap.size() != 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();
        int sum = left->freq + right->freq;
        minHeap.push(new Node{ '$', sum, left, right });
    }
    unordered_map<char, string> huffmanCode;
    printCode(minHeap.top(), "", huffmanCode);

    cout << "Huffman Codes are :\n" << '\n';
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << '\n';
    }
}

int main(){
    string S = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int n = S.size();
    HuffmanCodes(S, f, n);
    return 0;
}
