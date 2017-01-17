#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include <map>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	map<string, vector<int> > dp;
    	return help(input, dp);
	}


	vector<int> help(string input, map<string, vector<int> >& dp){
		if(dp.find(input)!=dp.end()) return dp[input];
		vector<int> result, temp;
		if(input.size()==0) return result;

		for(int i=0;i<input.size();i++){
    		if(input[i]=='+' || input[i]=='-' || input[i]=='*'){
    			temp = combine(help(input.substr(0,i), dp), help(input.substr(i+1), dp), input[i]);
    			result.insert(result.end(), temp.begin(), temp.end());
    		}
    	}
    	if(result.empty()) result.push_back(stoi(input));
    	dp[input] = result;
    	return result;
	}
    	   	
	vector<int> combine(vector<int> v1, vector<int>v2, char op){
		if(v1.size()==0) return v2;
		if(v2.size()==0) return v1;
		vector<int> result;
		int temp;
		for(int x: v1){
			for(int y:v2){
				switch(op){
					case '+': temp = x+y; break;
					case '-': temp = x-y; break;
					case '*': temp = x*y; break;
					default: cout<<"wrong operator!" ; 
				}
				result.push_back(temp);
			}
		}
		return result;
	}

};



int main(){
	Solution s;
	Vector<int> v = Vector<int>(s.diffWaysToCompute("2*3-4*5"));
	cout << v.toString();
}