#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsBackTrack(int m, int n) {  
        if(m==1 || n==1) return 1;  
        return uniquePathsBackTrack(m-1, n) + uniquePathsBackTrack(m, n-1);  
    }  
};

int main(){
    Solution s = Solution();
    int a,b;
    while(cin>>a,cin>>b){
        cout << s.uniquePathsBackTrack(a,b) << endl;
    }
    return 0;

}