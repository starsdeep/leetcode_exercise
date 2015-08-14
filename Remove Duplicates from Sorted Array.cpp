#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n==0)
			return 0;
		int head_idx;
		int tail_idx = head_idx = 1;
		int prev_value = A[0];
		
		while(head_idx < n){
			if(prev_value == A[head_idx]){
				while(head_idx < n && prev_value == A[head_idx]){
					head_idx++;
				}
				if(head_idx == n)
					break;
			}
			else{
				prev_value = A[head_idx];
				A[tail_idx++] = A[head_idx++];
			}
		}
		return tail_idx;
    }
};


int main(){
	Solution s = Solution();
	int A[3] = {1,2,2} ;
	cout << s.removeDuplicates(A,3);

}