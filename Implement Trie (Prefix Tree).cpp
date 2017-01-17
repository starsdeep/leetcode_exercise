 #include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    TrieNode* next[27];
    
    TrieNode() {
        for(int i=0;i<27;i++){
            next[i] = NULL;
        }
    }

    TrieNode(char v) {
        val = v;
        for(int i=0;i<27;i++){
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(word.size()==0) return;
        _insert(root, word, 0);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return _search(root, word, 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return _startsWith(root, prefix, 0);
    }

private:
    TrieNode* root;
    void _insert(TrieNode* root, string& word, int curr_len){
        if(curr_len==word.size()){
            root->next[0] = new TrieNode('\0');
            return;
        };
        char c = word[curr_len];
        int idx = c - 'a' + 1;
        //cout << curr_len << "----" << idx << ":"<< c << endl;
        if(root->next[idx]==NULL)
            root->next[idx] = new TrieNode(c);
        _insert(root->next[idx], word, curr_len+1);
    }

    bool _search(TrieNode* root, string& word, int curr_len){
        if(curr_len==word.size())
            return !(root->next[0]==NULL);
        
        char c = word[curr_len];
        int idx = c - 'a' + 1;
        if(root->next[idx]==NULL) return false;
        return _search(root->next[idx], word, curr_len+1);
    }

    bool _startsWith(TrieNode* root, string& word, int curr_len){
        if(curr_len==word.size()) return true;
        char c = word[curr_len];
        int idx = c - 'a' + 1;
        if(root->next[idx]==NULL) return false;
        return _startsWith(root->next[idx], word, curr_len+1);
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

//
//int main(){
//    Trie trie;
//    trie.insert("aa");
//    trie.insert("ke");
//    trie.insert("aaaaaaaaaaaaaa");
//    trie.insert("fafjalfjldsinefldsaljflajfdlajdflajldf");
//
//
//    cout << trie.search("a");
//}