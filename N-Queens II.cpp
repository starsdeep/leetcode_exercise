#include <iostream>
#include <vector>
using namespace std;

class Solution0 {
public:
    int totalNQueens(int n) {
		vector<vector<char> > board;
		int answer = 0;
		if(n<=0) return answer;
		for(int i=0;i<n;i++)
			board.push_back(vector<char>(n,'.'));
		
		help(board,answer,0);
		return answer;
    }

    void help(vector<vector<char> >board, int& answer, int row){
    	if(row == board.size()) return;
    	bool flag = false;
    	for(int i=0;i<board.size();i++){   		
    		if(board[row][i]=='.'){
    			vector<vector<char> >temp = board;
    			process(temp, row, i);
    			help(temp,answer,row+1);
    			flag = true;
    		}
    	}
    	if(row==board.size()-1 && flag) answer+=1;
    }

    void process(vector<vector<char> >& board, int i, int j){
    	int temp_i = i+1;
    	while(temp_i<board.size()) board[temp_i++][j] = '#';
    	temp_i = i+1;
    	int temp_j = j-1;
    	while(inRange(board.size(),temp_i,temp_j)) board[temp_i++][temp_j--] = '#';
    	temp_i = i+1;
    	temp_j = j+1;
    	while(inRange(board.size(),temp_i,temp_j)) board[temp_i++][temp_j++] = '#';
    }

    bool inRange(int n, int i, int j){
    	return i>=0 && i<n && j>=0 && j<n;
    }
};



class Solution{
public:
	int totalNQueens(int n) {
    vector<bool> col(n, true);
    vector<bool> anti(2*n-1, true);
    vector<bool> main(2*n-1, true);
    int count = 0;
    dfs(0, col, main, anti, count);
    return count;
}
void dfs(int i, vector<bool> &col, vector<bool>& main, vector<bool> &anti, int &count) {
        if (i == col.size()) {
            count++;
            return;
        }
       for (int j = 0; j < col.size(); j++) {
         if (col[j] && main[i+j] && anti[i+col.size()-1-j]) {
             col[j] = main[i+j] = anti[i+col.size()-1-j] = false;
             dfs(i+1, col, main, anti, count);
             col[j] = main[i+j] = anti[i+col.size()-1-j] = true;
      }
    }
}

};

int main(){
	Solution s;
	cout << s.totalNQueens(4);
}