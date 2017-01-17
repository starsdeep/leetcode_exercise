#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	vector<string> answer;
    	if(s.empty() || wordDict.empty()) return answer;
        int len = s.size();
        bool** res = new bool*[len];
        for(int i=0;i<len;i++)
        	res[i] = new bool[len];
        
        for(int i=0;i<len;i++){
        	for(int j=i;j<len;j++){
        		if(wordDict.find(s.substr(i,j-i+1))==wordDict.end())
        			res[i][j] = false;
        		else 
        			res[i][j] = true;
        	}   
        }

        
        string term = "";   
    	help(res,len,0,s,term,answer);
    	return answer;
    }

    void help(bool** res, int len, int start,string& s, string term, vector<string>& answer){
    	if(start==len){
    		answer.push_back(term);
    		return;
    	}
    	string temp;
    	for(int i=start;i<len;i++){
    		if(res[start][i]){
    			temp = term + " " + s.substr(start,i-start+1);
    			help(res, len, i+1, s, temp, answer);
    		}
    	}
    }

};

class Solution {
public:

	map<string, vector<string> > m;

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	if(m.count(s)) return m[s];
    	vector<string> result;
    	for(int i=0;i<s.size();i++){
    		string temp = s.substr(0,i+1);
    		if(wordDict.find(temp)!=wordDict.end()){
    			if(i+1 == s.size()){
    				result.push_back(temp);
    				break;
    			}
    			vector<string> v = wordBreak(s.substr(i+1), wordDict);
    			for(string s: v){
    				result.push_back(temp + " " + s);
    			}
    		}
    	}
    	m[s] = result;
    	return result;
    }
};



int main(){

}