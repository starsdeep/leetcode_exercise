#include <iostream>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	if(n==0)
    		return 0;
  		int head_idx;
  		int tail_idx = head_idx = 0;
  		while(head_idx < n){
  			if(A[head_idx] == elem){
  				head_idx++;
  			}
  			else{
  				A[tail_idx] = A[head_idx];
  				tail_idx++;
  				head_idx++;
  			}
  		}
  		return tail_idx;
  	}
};