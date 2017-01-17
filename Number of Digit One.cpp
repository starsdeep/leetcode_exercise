#include<iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
    	if(n<=0) return 0;
    	int a,b;
    	int result = 0;
    	for(long long i=1;i<=n;i*=10){

    		cout << "result: " << result << endl;

    		int a = n/i;
    		int b= n%i;
    		int digit = a%10;
    		if(digit>=2){
    			result += (a/10+1) * i;
    		}
    		else if(digit==1){
    			result += (a/10) * i + (b+1);
    		}
    		else
    			result += (a/10) * i;
    	}
    	return result;
    }
};


int main(){
	Solution s = Solution();
	cout << s.countDigitOne(110);
}