#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int* res = new int[n+1];
        res[0] = 1, res[1] = 1;
        for(int len=2;len<=n;len++){
        	res[len]=0;
        	for(int i=1;i<=len;i++){
        		res[len] += res[i-1] * res[len-i];
        	}
        }
        int result = res[n];
        delete[] res;
        return result;
    }
};

int main(){
	Solution s = Solution();
	cout << s.numTrees(4);
}