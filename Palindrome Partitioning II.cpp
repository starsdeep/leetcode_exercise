#include <iostream>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int minCut(string s) {
    	if(s.size()<=1) return 0;
        int dp[s.size()+1];
        dp[0] = 0, dp[1] = 1;
        for(int i=1;i<s.size();i++){
        	dp[i+1] = dp[i] + 1;
        	for(int j=0;j<i;j++){
        		if(isPalindrome(s,j,i)){
        			dp[i+1] = min(dp[i+1], dp[j]+1);
        		}
        	}
        }
        return dp[s.size()];
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

//上面的是原始方法，在计算isPalindrome(s,j,i)的时候其实还能加速计算。


class Solution {
public:
    int minCut(string s) {
        const int N = s.size();
        bool isPalindrome[N][N];
        fill_n(&isPalindrome[0][0],N*N,false);
        int dp[N+1];
        for(int i=0;i<=N;i++) dp[i] = i-1;
        //dp[0] = -1;
        for(int i=0;i<N;i++){
        	for(int j=i;j>=0;j--){
        		if(s[i]==s[j] && (i-j<2 || isPalindrome[j+1][i-1])){
        			dp[i+1] = min(dp[i+1], dp[j]+1);
        			isPalindrome[j][i] = true;
        		}
        	}
        }
        for(int v:dp)
        	cout << v << endl;
        return dp[N];
    }
};

// using symmetrical properties, instead of dp。 but the key idea is the same




class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};

int main(){
	Solution s;
	string ss = "abba";
	cout << endl << s.minCut(ss);


}