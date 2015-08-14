#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n ==1)
            return 1;
        int k=m+n-2;
        int max = m;
        int min = n;
        if(m<n){
            max = n;
            min = m;
        }
        double n1 = max;
        double i = max+1;
        while(i<=k){
            n1 *= i;
            i++;
        }
        double d = 1;
        i=2;
        //cout << "d:" << d;
        //cout << "n1:" << n1;
        while(i <= min-1){
            d *= i;
            i++;
        }
        cout << n1 << " / " << d << endl;
        return int(n1/d);
    }
};

int main(){
    Solution s = Solution();
    int a,b;
    while(cin>>a,cin>>b){
        cout << s.uniquePaths(a,b) << endl;
    }
}

