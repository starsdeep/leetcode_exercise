

class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int global_max = A[0];
    	int local_max = A[0];

    	for(int i=1;i<n;i++){
    		local_max = A[i] > local_max + A[i] ? A[i]: local_max + A[i];
    		global_max = global_max > local_max ? global_max: local_max;
    	}
    	return global_max;
    }
};