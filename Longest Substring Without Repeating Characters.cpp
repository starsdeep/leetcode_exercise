#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  		if(s.size()<=1) return s.size();
  		int global = 1;
  		map<char, int> m;
  		m[s[0]] = 0;
  		int start = 0;
  		for(int i=1;i<s.size();i++){
  			if(m.find(s[i])!=m.end() && m[s[i]]>=start){
  				start = m[s[i]]+1;
  				m[s[i]] = i;
  			}
  			else{
  				m[s[i]] = i;
  				global = max(global, i-start+1);
  			}
  			
  		}
  		return global;
    }
};

int main(){
	Solution s;
	string ss = "aab";
	cout << s.lengthOfLongestSubstring(ss);
}