#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	if(!s.size() || nRows == 1)
    		return s;

    	vector<vector<char> > row_vec (nRows, vector<char>());
    	for(int i = 0;i < s.size(); ++i){
    		int idx = i % (2 * nRows - 2);
    		if(idx < nRows){
    			row_vec[idx].push_back(s[i]);
    		}
    		else{
    			int idx2 = (2*nRows-2) - idx;
    			row_vec[idx2].push_back(s[i]);
    		}

    	}
    	string result;
    	for(int i = 0; i < row_vec.size(); ++i){
    		for(int j=0; j < row_vec[i].size(); ++j){
    			result += row_vec[i][j];
    		}
    	}
    	return result;
    }
};

int main(){
	Solution sol;
	string s = "A";
	cout << sol.convert(s,1);
}