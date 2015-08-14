#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {

public:

    bool wordBreak(string s, unordered_set<string> &dict){
      s = '#'+ s;
      vector<bool> res = vector<bool>(s.size(), false);
      res[0] = true;
      for(int i=1;i<res.size();i++){
        for(int j=0;j<i;j++){
          if(res[j] && dict.find(s.substr(j+1,i-j))!=dict.end()){
            res[i]=true;
            break;
          }
        }
      }
      return res[s.size()-1];
    }



    bool wordBreak1(string s, unordered_set<string> &dict) {
        string str1;
        string str2;

        if(dict.find(s)!=dict.end())
        	return true;
        if(s.size()<=1)
        	return false;
        
        return help(s,dict,0);
    }

    bool help(string& s, unordered_set<string> &dict, int start){
      if(start==s.size())
        return true;
      string temp;
      for(int i=start+1;i<s.size();i++){
        temp = s.substr(start, i-start);
        if(dict.find(temp)!=dict.end()){
          if(help(s, dict, i))
            return true;
        }
      }
      return false;
    }

};

int main(){
	cout << "hello";
  Solution s = Solution();
 

}