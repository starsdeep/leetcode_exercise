#include <limits>
#include <iostream>
#include <cmath>
using namespace std;

class Solution1 {
public:
    int divide(int dividend, int divisor) {
        unsigned int divd = dividend, divs = divisor;//使用unsigned防止-2147483648符号取反后溢出
        if(divisor < 0)divs = -divs;//负数全部转化为正数
        if(dividend < 0)divd = -divd;
         
        int res = 0;
        while(divd >= divs)
        {
            long long a = divs;//使用long long防止移位溢出
            int i;
            for(i = 1; a <= divd; i++)
                a <<= 1;
            res += (1 << (i-2));
            divd -= (divs << (i-2));
        }
         
        return (dividend>0 ^ divisor>0) ? -res : res;
    }
};



class Solution {
public:
    int divide(int d1, int d2) {
  		if(d2==0)
  			return numeric_limits<int>::max();
  		unsigned int dividend = d1, divisor = d2;//使用unsigned防止-2147483648符号取反后溢出
        if(d2 < 0)divisor = -divisor; 
        if(d1 < 0)dividend = -dividend;
  		
  		long long int t = 1;
  		int r = 0;
  		while(dividend >= divisor){
  			long long int temp_divisor = divisor;
  			while(dividend>temp_divisor){
  				temp_divisor = temp_divisor<<1;
  				t = t<<1;
  			}
  			if(temp_divisor>dividend){
  				t = t>>1;
  				temp_divisor = temp_divisor>>1;
  			}
  			r+=t;
  			t=1;
  			dividend -= temp_divisor;
  		}
  		return (d1>0 ^ d2>0) ? -r : r;
    }
};

int main(){
	Solution s = Solution();
	int dividend, divisor;
	while(cin>>dividend, cin>>divisor)
		cout << s.divide(dividend, divisor)<<endl;
	// long long int a = 1;
	// a = a << 31;
	// long long int temp_divisor = (a << 1);
	// cout << (temp_divisor>a);
	// cout << a << " " << unsigned(-1) << " "<<b << " " << -b << endl;
}
