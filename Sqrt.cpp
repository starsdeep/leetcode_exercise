#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    int sqrt1(int x) {
    	if(x==1)
    		return 1;
    	unsigned long long int begin=0,end=x,median=x/2;
    	while(true)
    		if(median*median==x)
    			return median;
    		else if(median*median>x){
    			end = median;
    			median = (begin + end)/2;
    		}
    		else if(median*median<x){
    			if((median+1)*(median+1)>x)
    				return median;
    			begin = median;
    			median = (begin + end)/2;
    		}
    }

    int sqrt2(int x) {
        if (x==1 || x==0) return x;
        double x0 = 1;
        double x1 = (x0+ x/x0)/2;
        while (abs(x1-x0)>=1){
            x0=x1;
            x1 = (x0+ x/x0)/2;
        }
        return int(x1);
    }

    int sqrt3(int x){
        if(x < 4) return x == 0 ? 0 : 1;
        int res = 2 * sqrt3(x/4);
        if((res+1) * (res+1) <= x && (res+1) * (res+1) >= 0) return res+1;
        return res;
    }

    int sqrt4(int x) {
        long ans = 0;
        long bit = 1l << 16;
        while(bit > 0) {
            ans |= bit;
            if (ans * ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }
        return (int)ans;
    }
};




int main(){
	Solution s = Solution();
	cout << s.sqrt1(26);

}