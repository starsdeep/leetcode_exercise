#include <iostream>
#include <cstdlib>

using namespace std;

class TrieNode {
public:
    bool isKey;
    TrieNode* next[26];
    TrieNode(): isKey(false) {
        memset(next, NULL, sizeof(TrieNode*) * 26);
    }
};



class WordDictionary {
public:
	
	WordDictionary(){
		root = new TrieNode();
	}

    // Adds a word into the data structure.
    void addWord(string word) {
    	TrieNode* p = root;
    	int idx;
    	for(int i=0;i<word.size();i++){
    		idx = word[i]-'a';
    		if(p->next[idx]==NULL){
    			p->next[idx] = new TrieNode();
    		}
    		p = p->next[idx];
    	}
    	p->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	return _search(root, word, 0);
    }

private:
	TrieNode* root;

	bool _search(TrieNode* root, string& word, int l){
		if(l==(word.size()) && root->isKey) return true;
		if(word[l]=='.'){
			for(int i=0;i<26;i++){
				if(root->next[i] && _search(root->next[i], word, l+1))
					return true;
			}
			return false;
		}
		else{
			if(root->next[word[l]-'a'])
				return _search(root->next[word[l]-'a'], word, l+1);
			else
				return false;
		}
	}

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(){
	WordDictionary wordDictionary;
	wordDictionary.addWord("abc");
	wordDictionary.addWord("pattern");
	cout << wordDictionary.search("a.c");

}