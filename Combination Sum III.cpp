#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > answer;
        vector<int> temp;
        help(answer,temp,k,n);
    	return answer;
    }

    void help(vector<vector<int> >& answer, vector<int>temp, int k, int n){
    	if(temp.size()==k){
    		if(n==0)
    			answer.push_back(temp);
    		return;
    	}
    	
    	for(int i=temp.size()==0 ? 1:temp.back()+1;i<=9;i++){
    		if(i>n) break;
    		temp.push_back(i);
    		help(answer, temp, k, n-i);
    		temp.pop_back();
    	}
    }
};

int main(){

}