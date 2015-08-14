#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_vector(vector<string> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
  		int res = 1;
    	vector<string> r;
    	string str;

    	if(n==0) return r;
    	str += '(';
		help(r, res, str, n-1, n);
		return r;
    }

    void help(vector<string>& r,int res, string str, int left, int right){
    	if(right==0){
    		r.push_back(str);
    		return;
    	}
    	if(res==0)
			help(r,res+1,str+'(',left-1,right);
    	else{
    		help(r,res-1,str+')',left,right-1);
    		if(left)
    			help(r,res+1,str+'(',left-1,right);
    	}
    }
};

int main(){
	Solution s = Solution();
	vector<string> r = s.generateParenthesis(3);
	print_vector(r);
}

