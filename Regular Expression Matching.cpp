#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string t) {
  		
  		//change ** -> *
  		string p = "";
  		for(int i=0;i<t.size();i++){
  			if(i>0 && t[i]=='*' && t[i-1]=='*')
  				continue;
  			p += t[i]; 
  		}
		bool dp[p.size()+1][s.size()+1];

  		for(int i=0;i<p.size();i++) dp[i][0] = false;
  		for(int j=0;j<s.size();j++) dp[0][j] = false;
  		
  		dp[0][0] = true;

  		for(int i=1;i<=p.size();i++){
  			for(int j=1;j<=s.size();j++){
  				if(p[i-1]!='.' && p[i-1]!='*'){
  					dp[i][j] = dp[i-1][j-1] && (s[j-1]==p[i-1]);
  				}
  				else if(p[i-1]=='.'){
  					dp[i][j] = dp[i-1][j-1];
  				}
  				else{
  					if(i==2)
  						dp[2][0] = 1;
  					if(p[i-1]=='.')
  						dp[i][j] = dp[i][j-1];
  					else{
  						dp[i][j] = dp[i-2][j] || dp[i-1][j-1] || (dp[i][j-1] && (s[j-1]==p[i-2]));
  					}
  					//dp[i][j] = dp[i-2][j];
  				}
  				//cout << "i: " << i << ", j: " << j << "   : " << dp[i][j] << endl; 
  			}
  		}
  		
  		return dp[p.size()][s.size()];
    }
};

int main(){
	Solution s;
	cout << s.isMatch("aab", "ab*a*c") << endl;

}