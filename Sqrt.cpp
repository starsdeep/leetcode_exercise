#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    int sqrt(int x) {
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
};


int main(){
	Solution s = Solution();
	cout << s.sqrt(26);

}