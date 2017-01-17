#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
    	string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    	if(digits=="") return res;
    	res.push_back("");
    	
    	for(int i=0;i<digits.size();i++){
    		string chars = charmap[digits[i]-'0'];
    		vector<string> temp_res;
    		for(char c : chars){
    			for(int j=0;j<res.size();j++){
    				temp_res.push_back(res[j] + c);
    			}
    		}
    		res = temp_res;
    	}
    	return res;
    }
};

int main(){

}