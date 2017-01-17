#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 1;
        int i=0;
        int result = 0;
        while((i++)<32){
        	
        	result += mask;
        	//cout << "mask: " << mask << endl;
        	for(int j=m;j<=n;j++){
        		if((mask & j) == 0){
        			result -= mask;
        			break;
        		}
        	}
        	//cout << "result: " << result << endl;
        	mask = mask << 1;
        }
        return result;
    }
};


int main(){
	Solution s;
	//cout << (6 & 1);
	cout << s.rangeBitwiseAnd(5,7);

}