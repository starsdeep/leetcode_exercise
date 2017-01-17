#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	
        while(num%2==0) num /= 2;
        while(num%3==0) num /= 3;
        while(num%5==0) num /= 5;
        return num==1;
    }
};

int main(){
	Solution s;
	cout << s.isUgly(17);
}