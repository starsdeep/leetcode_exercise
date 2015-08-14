#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    }
    bool help(vector<vector<char> > board, string& word, int i, int j, int start){
    	//cout << i << "  " << j << endl;
    	if(start==word.size())
    		return true;
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
    	return false;
    }
    bool inRange(vector<vector<char> >& board, int i, int j){
    	return i>=0 && i<board.size() && j>=0 && j<board[0].size();
    }
};

int main(){
	Solution s= Solution();
	char c1[] = {'A','B','C','E'};
	char c2[] = {'S','F','C','S'};
	char c3[] = {'A','D','E','E'};
	vector<vector<char> > board;
	board.push_back(vector<char>(c1,c1+4));
	board.push_back(vector<char>(c2,c2+4));
	board.push_back(vector<char>(c3,c3+4));
	cout << s.exist(board,"ABCCED");

}