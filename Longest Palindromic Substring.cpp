#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		if(s.size()<=1) return s;
    	int global_len = 0;
    	int idx=0;
    	int local_len = 0;
    	bool odd = false;
    	for(int i=0;i+1<s.size();i++){
    		if(s[i]==s[i+1]){
    			local_len = get_len(s,i-1,i+2);
    			if(2*local_len>global_len){
    				global_len = 2*local_len;
    				idx = i;
    				odd=false;
    			}
    		}
    		if(i>0 && s[i-1]==s[i+1]){
    			local_len = get_len(s,i-1,i+1);
    			if(2*local_len-1>global_len){
    				global_len = 2*local_len-1;
    				idx = i;
    				odd = true;
    			}
    		}
    	}
    	if(odd)
    		return s.substr(idx-(global_len-1)/2, global_len);
    	return s.substr(idx-global_len/2+1,global_len);
    }

    int get_len(string& s, int left, int right){
    	int len = 1;
    	while(left>=0 && right<s.size() && s[left]==s[right]){
    		len++;
    		left--;
    		right++;
    	}
    	return len;
    }
};

int main(){
	string str = "bb";
	Solution s = Solution();
	cout << s.longestPalindrome(str);
}