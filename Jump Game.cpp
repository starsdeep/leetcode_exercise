#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
  		int max_jump = A[0];
  		if(max_jump==0)
  			if(n==1)
  				return true;
  			else
  				return false;
  		for(int i=1;i<n;i++){
  			max_jump = max_jump-1 > A[i]?max_jump-1: A[i];
  			if(i+max_jump==n-1)
  			    return true;
  			if(max_jump==0)
  				return false;
  			
  		}
  		return true;
    }
};

/*
class Solution {
public:
    bool canJump(int A[], int n) {
        return help(A,n,0);
    }

    bool help(int A[], int n, int idx){
    	if(idx==n)
    		return true;
    	int value = A[idx];
    	if(value==0)
    		return false;
    	if(idx + value >= n)
    		return true;
    	int temp_i = idx;
    	for(int i=value;i>temp_i;i--){
    		if(help(A,n,idx+i))
    			return true;
    	}
    	return false;
    }
};
*/
int main(){
	Solution s = Solution();
	int A[] = {2,3,1,1,4};
	cout << s.canJump(A, 5);
}