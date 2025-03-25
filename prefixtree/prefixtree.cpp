#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() {
        isWord=false;
    }
};
struct Trie {

    TrieNode* root;


    Trie() {
        root = new TrieNode();
    }


    ~Trie() {
        deleteTrie(root);
    }


    // Вставка слова в дерево
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isWord = true;
    }


    //пошук по префіксу
    void findByPrefix(const string& prefix, vector<string>& result) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                return;
            }
            current = current->children[c];
        }
        findAllWordsFromNode(current, prefix, result);
    }


    void findAllWordsFromNode(TrieNode* node, const string& currentPrefix,vector<string>& result) {
        if (node->isWord) {
            result.push_back(currentPrefix);
        }
        for (auto& pair : node->children) {
            findAllWordsFromNode(pair.second, currentPrefix + pair.first, result);
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }

    void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }
};

int main() {

    Trie trie;

    ifstream file("words_alpha.txt");
    if (!file.is_open()) {
        cerr << "Не вийшло відкрити файл" <<endl;
        return 1;
    }

    string word, word1;
    while (file >> word) {
        trie.insert(word);
    }
    file.close();







    cin >> word1;
    vector<string> words;
    trie.findByPrefix(word1,words);
  
    return 0;
}