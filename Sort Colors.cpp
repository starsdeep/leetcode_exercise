#include <iostream>

class Solution {
public:
    void sortColors(int A[], int n) {
		int a=0,b=0,c=0;
		for(int i=0;i<n;i++){
			if(A[i]==0)
				a++;
			else if(A[i]==1)
				b++;
			else
				c++;
		}     
		int i=0;   
		while(i<a)
			A[i++] = 0;
		while(i<a+b)
			A[i++] = 1;
		while(i<a+b+c)
			A[i++] = 2;
		return;
    }

};