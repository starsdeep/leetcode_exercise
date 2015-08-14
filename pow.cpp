#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
    	int pos_n = int(abs(n));
    	double result;
        if(pos_n==0){
        	return 1;
        }
        else if(pos_n==1){
            result = x; 
        }
        else{
        	double temp;
        	if(pos_n%2==0){
        		temp = pow(x,pos_n/2);
        		result = temp * temp;
        	}
        	else{
        		temp = pow(x,(pos_n-1)/2);
        		result = x * temp * temp;
        	}
    	}
        if(n<0)
        	return 1.0 / result;
        else{
        	return result;
        }

    }
};

int main(){
	Solution s = Solution();
	cout << s.pow(8.88023,3);
}

