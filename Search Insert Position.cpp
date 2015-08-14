#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        for(int i=0;i<n;i++){
        	if(A[i]>=target)
        		return i;
        }
    }
};

int main(){
	int A[] = {1,3,5,6};
	Solution s = Solution();
	cout << s.searchInsert(A,4,5);
}