#include <iostream>
#include <string>

using namespace std;
/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	if(s[0]=='\0'){
    		if(allstar(p) || p[0] == '?' || p[0] =='\0')
    			return true;
    		return false;
    	}
    	if(p[0]=='\0' && s[0]!='\0'){
    		return false;
    	}
    	if(p[0]=='*'){
    		return isMatch(s, p+1) || isMatch(s+1, p) || isMatch(s+1, p+1);
    	}
    	if(p[0]=='?' || p[0]==s[0]){
    		return isMatch(s+1, p+1);
    	}
    };

    bool allstar(const char* s){
    	int i=0;
    	while(s[i]!='\0'){
    		if(s[i] != '*')
    			return false;
    		i++;
    	}
    	return true;
    }

};
*/


class Solution{
    
    bool isMatch(string s, string p) {
        bool (*res)[p.size()+1] = new bool[s.size()+1][p.size()+1];
        if(s=="" && p=="" || s="" && p="*")
            return true;
        res[0][0] = true;
        int i=0;
        for(int j=0;j<p.size();j++){
            if(p[j]!='*'){
                for(int i=0;i<s.size();i++){
                    
                }

                if (p[j]=='?' || p[j]==s[i]){
                    res[i][j] = res[i-1][j-1];
                    i++;
                }
                else
                    res[i][j] = false;
            }
            else{
                res[i][j] = false;
                for(int k=1;k<i;k++){
                    if(res[k][j-1]){
                        res[i][j] = true;
                        break;
                    }
                }
            }
                
        }
    }


    
            




    }

};


int main(){
	Solution s = Solution();
	cout << s.isMatch("aa", "*");
	cout << s.isMatch("aab", "c*a*b");

}