
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int result = 0;
    	for(int i=0;i<32;i++){
    		int temp = 0;
    		int mask = 1 << i;
    		for(int j=0;j<n;j++){
    			temp += (A[j] & mask) >> i;
    		}
    		result += (temp%3) << i;
    	}
    	return result;
};