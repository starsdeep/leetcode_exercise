#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int* res = new int[n+1];
        res[0]=0, res[1]=1, res[2]=2;
        for(int i=3;i<=n;i++){
        	res[i]=res[i-1]+res[i-2];
        }
        delete[] res;
        return res[n];
    }
};

int main(){
	Solution s = Solution();
	cout << s.climbStairs(3);
}