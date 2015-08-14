#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = (m+n);
		if(total & 0x1)
			return findKth(A,m,B,n,total/2+1);
		return (findKth(A,m,B,n,total/2) + findKth(A,m,B,n,total/2+1))/2.0;
    }

    double findKth(int a[], int m, int b[], int n, int k){
    	// assume m <= n
    	if (m > n)  
        	return findKth(b, n, a, m, k);  
    	if (m == 0)  
        	return b[k - 1];  
    	if (k == 1)  
        	return min(a[0], b[0]);  
    	
    	int part1 = min(k/2, m);
    	int part2 = k - part1;
    	if(a[part1-1] < b[part2-1]){
    		return findKth(a+part1, m-part1,b,n,k-part1);
    	}
    	else if(a[part1-1]==b[part2-1]){
    		return a[part1-1];
    	}
    	else{
    		return findKth(a,m,b+part2,n-part2,k-part2);
    	}
    }
};

int main(){
	cout << "hello\n";
	int A[] = {1,2};
	int B[] = {1,2};
	Solution s = Solution();
	cout << s.findMedianSortedArrays(A,2,B,2);
}
