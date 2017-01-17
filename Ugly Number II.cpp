#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    	if(n<=1) return 1;
        int dp[n+1];
        dp[0] =1;
        int i=0,j=0,k=0;
        int it=1;
        while(it<n){
        	dp[it] = min(min(dp[i]*2,dp[j]*3),dp[k]*5);
        	if(dp[it]==dp[i]*2) i++;
        	if(dp[it]==dp[j]*3) j++;
        	if(dp[it]==dp[k]*5) k++;
        	//cout << it << ":" << dp[it] << endl;
        	it++;

        }
        return dp[n-1];
    }
};

int main(){
	Solution s;
	cout << s.nthUglyNumber(10);
}