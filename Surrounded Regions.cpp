#include <set>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void print_2d_vector(vector<vector<char> >x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
}

void print_vector(vector<char> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}




//flood fill 算法，board 开始fill确实更简洁，跌打的写法也更好，只需要更少的代码量
class Solution {
public:
    void solve(vector<vector<char> > &board) {
    	if(board.size()<=1 || board[0].size()<=1)
    		return;
    	fill_from_board(board,'O','Y');
    	replace(board,'O','X');
    	replace(board,'Y','O');	
    }
    void fill_from_board(vector<vector<char> >& board, char old_c, char new_c){
    	int i_size = board.size(), j_size = board[0].size();
    	for(int i=0;i<i_size;i++){
    		if(board[i][0]==old_c) fill(board,i,0,old_c,new_c);
    		if(board[i][j_size-1]==old_c) fill(board,i,j_size-1,old_c,new_c);
    	}
    	for(int j=1;j<j_size-1;j++){
    		if(board[0][j]==old_c) fill(board,0,j,old_c,new_c);
    		if(board[i_size-1][j]==old_c) fill(board,i_size-1,j,old_c,new_c);
    	}
    }         
    void fill(vector<vector<char> >& board, int i, int j, char old_c, char new_c){
    	queue<int> q;
    	q.push(i*board[0].size()+j);
    	int value;
    	while(!q.empty()){
    		value = q.front(); q.pop();
    		i = value / board[0].size();
    		j = value % board[0].size();
    		if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=old_c)
    			continue;
    		board[i][j]=new_c;
    		q.push((i-1)*board[0].size()+j);
    		q.push((i+1)*board[0].size()+j);
    		q.push(i*board[0].size()+j-1);
    		q.push(i*board[0].size()+j+1);
    	} 
    }
    void fill_recursive(vector<vector<char> >& board, int i, int j, char old_c, char new_c){
    	if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=old_c)
    		return;
    	board[i][j] = new_c;
    	fill_recursive(board,i-1,j,old_c,new_c);
    	fill_recursive(board,i+1,j,old_c,new_c);
    	fill_recursive(board,i,j-1,old_c,new_c);
    	fill_recursive(board,i,j+1,old_c,new_c);
    }

    void replace(vector<vector<char> >& board, char old_c, char new_c){
    	for(int i=0;i<board.size();i++)
    		for(int j=0;j<board[0].size();j++)
    			if(board[i][j]==old_c)
    				board[i][j]=new_c;
    }



};








// 过不了大数据测试，栈溢出
class Solution1 {
public:
    void solve(vector<vector<char> > &board) {
    	if(board.size()<=1 || board[0].size()<=1)
    		return;
  		set<int> visited, local_visited;
  		bool is_surrounded;
  		for(int i=0;i<board.size();i++){
  			for(int j=0;j<board[0].size();j++){	
  				if(board[i][j]=='O' && visited.find(i*board.size()+j)==visited.end()){
  					local_visited.clear();
  					if(onRegion(i,j,board)==false && dfs(i,j,board,local_visited)){
  						local_visited.clear();
  						dfs(i,j,board,local_visited,true);
  					}
  					else{
  						visited.insert(i*board.size()+j);
  						visited.insert(local_visited.begin(),local_visited.end());
  					}
  				}
  			}
  		}
  		return;
  	}

  		bool dfs(int i, int j, vector<vector<char> >& board, set<int>& local_visited, bool capture=false){
  			local_visited.insert(i*board.size()+j);
  			if(capture)
  				board[i][j]='X';
  			if(local_visited.find((i-1)*board.size()+j)==local_visited.end() && inRegion(i-1,j,board) && board[i-1][j]=='O'){
  				if(onRegion(i-1,j,board))
  					return false;
  				if(dfs(i-1,j,board,local_visited,capture)==false)
  					return false;
  			}
  			if(local_visited.find((i+1)*board.size()+j)==local_visited.end() && inRegion(i+1,j,board) && board[i+1][j]=='O'){
  				if(onRegion(i+1,j,board))
  					return false;
  				if(dfs(i+1,j,board,local_visited,capture)==false)
  					return false;
  			}
  			if(local_visited.find(i*board.size()+j-1)==local_visited.end() && inRegion(i,j-1,board) && board[i][j-1]=='O'){
  				if(onRegion(i,j-1,board))
  					return false;
  				if(dfs(i,j-1,board,local_visited,capture)==false)
  					return false;
  			}
  			if(local_visited.find(i*board.size()+j+1)==local_visited.end() && inRegion(i,j+1,board) && board[i][j+1]=='O'){
  				if(onRegion(i,j+1,board))
  					return false;
  				if(dfs(i,j+1,board,local_visited,capture)==false)
  					return false;
  			}
  			return true;
  		}

  		bool inRegion(int i, int j, vector<vector<char> >& board){
  			return i>=0 && i<board.size() && j>=0 && j<board[0].size();
  		}    
  		bool onRegion(int i, int j, vector<vector<char> >& board){
  			return i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1;
  		}
};

int main(){
	//cout << "hello";
	Solution s = Solution();
	vector<vector<char> > board;
	vector<char> v = vector<char>(4,'X');
	board.push_back(v);
	v[1]=v[2]='O';
	board.push_back(v);
	v[1]='X';v[3]='O';v[3]='X';
	board.push_back(v);
	v[1]='O',v[2]='X';
	board.push_back(v);
	print_2d_vector(board);
	cout << endl;

	s.solve(board);

	print_2d_vector(board);

}

