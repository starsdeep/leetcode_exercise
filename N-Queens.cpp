#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

void print_res(int** res, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {

        int** res;
		res = new int*[n];
		for (int i = 0;i<n;i++)
    		res[i] = new int[n];
        //memset(res, 0, sizeof(res[0][0]) * n * n);
        for(int i=0;i<n;i++)
        	for(int j=0;j<n;j++)
        		res[i][j] = 0;
        
     

        int currRow = 0;
        vector<vector<string> > result;
        int t;
        for(int i=0;i<n;i++){
        	t = process(res, n, currRow, i);
        	solve(res,n, currRow+1, result);
        	process(res,n,currRow,i,true,t);
        }

        for (int i = 0;i<n;i++)
    		delete[] res[i];
		delete[] res;
        
        return result;
    }

    void solve(int** res, int n, int row, vector<vector<string>>& result){
    	if(row >= n){
    		result.push_back(res2str(res, n));
    		return;
    	}
    	int t;
    	for(int i=0;i<n;i++){
    		if(res[row][i]==0){
    			t = process(res,n,row,i);
    			solve(res,n,row+1,result);
    			process(res,n,row,i,true,t);
    		}
    	}
    }

    vector<string> res2str(int** res, int n){
    	vector<string> r;
    	for(int i=0;i<n;i++){
    		string s;
    		for(int j=0;j<n;j++){
    			if(res[i][j] == -1)
    				s+="Q";
    			else
    				s+=".";
    		}
    		r.push_back(s);
    	}
    	return r;
    }

    int process(int** res, int n, int row, int column, bool reverse=false, int original_t=0){
    	int influence = 1;
    	if(reverse)
    		influence = -1;

    	int t = res[row][column];
    	for(int i=0;i<n;i++){
    		res[row][i] += influence;
    		res[i][column] += influence;
    	}
    	int temp_row = row;
    	int temp_column = column;
    	while(inRegion(n, ++temp_row, ++temp_column))
    		res[temp_row][temp_column] += influence;
    	temp_row = row;
    	temp_column = column;
    	while(inRegion(n, --temp_row, --temp_column))
    		res[temp_row][temp_column] += influence;
    	temp_row = row;
    	temp_column = column;
    	while(inRegion(n, --temp_row, ++temp_column))
    		res[temp_row][temp_column] += influence;
    	temp_row = row;
    	temp_column = column;
    	while(inRegion(n, ++temp_row, --temp_column))
    		res[temp_row][temp_column] += influence;
    	
    	res[row][column] = -1;
    	if(reverse)
    		res[row][column] = original_t;
    	return t;
    }

	bool inRegion(int n, int row, int column){
		if(row>=0 && row<n && column>=0 && column<n)
			return true;
		return false;
	}
};




int main(){
	Solution s = Solution();
	cout << "hello" << endl;
	int n=4;
	
	
	vector<vector<string> > r = s.solveNQueens(4);
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r[i].size();j++){
			cout << r[i][j] << endl;
		}
		cout << "--------------------------" << endl;
	}
	return 0;
}




