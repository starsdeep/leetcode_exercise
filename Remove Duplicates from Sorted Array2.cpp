#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2)
        	return n;
        int idx1=2,idx2=2;
        while(idx2<n){
        	while(A[idx1-2]==A[idx1-1] && A[idx1-1]==A[idx2]){
        		idx2++;
        		if(idx2==n)
        			return idx1;
        	}
        	A[idx1] = A[idx2];
        	idx1++;
        	idx2++;
        }
        return idx1;
    }
};

int main(){
	Solution s = Solution();
	int A[] = {1,1,1};
	cout << s.removeDuplicates(A,3);
}