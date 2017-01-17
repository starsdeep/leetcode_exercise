#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:
	class Node{
	public:
		bool isLeaf;
		int value;
		Node* next[26];
		Node(bool b=false){
			isLeaf = b;
			value = -1;
			fill_n(&next[0], 26, nullptr); 
		}
	};

	void insert(Node* root, string& word, int i){
		Node* curr = root;
		int idx;
		for(char c: word){
			idx = c-'a';
			if(curr->next[idx]==nullptr)
				curr->next[idx] = new Node();
			curr = curr->next[idx];
		}
		curr->value = i;
		curr->isLeaf = true;
	}
	
    void buildTries(Node* root, vector<string>& words){
    	for(int i=0;i<words.size();i++)
    		insert(root, words[i], i);
    }	

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	vector<string> answer;
		if(words.size()==0 || board.size()==0 || board[0].size()==0) return answer;
		//unique(words.begin(), words.end());
		Node* root = new Node();
		buildTries(root, words);
		Node* curr = root;
		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[0].size();j++){
				dfs(answer,board,words,curr,i,j);
			}
		}
		return answer;
    }

    void dfs(vector<string>& answer, vector<vector<char> >& board, vector<string>& words ,Node* curr, int i, int j){
    	if(!inRange(board,i,j) || board[i][j]=='#') return;
    	if(curr->next[board[i][j]-'a']==nullptr) return;

		if(curr->next[board[i][j]-'a']->isLeaf){
    		answer.push_back(words[curr->next[board[i][j]-'a']->value]);
    		curr->next[board[i][j]-'a']->isLeaf = false;
    	
    	}
		char temp = board[i][j];
		board[i][j] = '#';
    	dfs(answer, board, words, curr->next[temp-'a'],i-1,j);
    	dfs(answer, board, words, curr->next[temp-'a'],i+1,j);
    	dfs(answer, board, words, curr->next[temp-'a'],i,j-1);
    	dfs(answer, board, words, curr->next[temp-'a'],i,j+1);
    	board[i][j] = temp;
    }

    bool inRange(vector<vector<char> >& board, int i, int j){
    	return i>=0 && i<board.size() && j>=0 && j<board[0].size();
    }

};

int main(){
	Solution s;
	vector<vector<char> > v;
	vector<char> vv = {'a', 'a'};
	v.push_back(vv);

	vector<string> words = {"a"};
	s.findWords(v, words);

}