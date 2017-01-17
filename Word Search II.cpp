#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> answer;
        set<string> s;
        for(string word: words){
        	if(s.find(word)==s.end())
        		if(exist(board,word))
        			answer.push_back(word);
        }
        return answer;
    }

    bool exist(vector<vector<char> > &board, string word) {
    	if(board.size()==0 || word.size()==0)
    		return false;
        for(int i=0;i<board.size();i++){
        	for(int j=0;j<board[0].size();j++){
        		if(board[i][j]==word[0]){
        			if(help(board,word,i,j,1)){
        				return true;
        			}
        		}
        	}
        }
        return false;
    }
    bool help(vector<vector<char> >& board, string& word, int i, int j, int start){
    	//cout << i << "  " << j << endl;
    	if(start==word.size())
    		return true;
    	char tmp = board[i][j];
    	board[i][j] = '#';
    	if(inRange(board,i-1,j) && board[i-1][j]==word[start])
    		if(help(board,word,i-1,j,start+1))
    			return true;
    	if(inRange(board,i+1,j) && board[i+1][j]==word[start])
    		if(help(board,word,i+1,j,start+1))
    			return true;
    	if(inRange(board,i,j-1) && board[i][j-1]==word[start])
    		if(help(board,word,i,j-1,start+1))
    			return true;
    	if(inRange(board,i,j+1) && board[i][j+1]==word[start])
    		if(help(board,word,i,j+1,start+1))
    			return true;
    	board[i][j] = tmp;
    	return false;
    }
    bool inRange(vector<vector<char> >& board, int i, int j){
    	return i>=0 && i<board.size() && j>=0 && j<board[0].size();
    }
};

int main(){

}