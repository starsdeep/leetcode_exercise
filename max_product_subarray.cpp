#include<iostream>

using namespace std;


int max(int x,int y){
	return x>y?x:y;
}

int min(int x,int y){
	return x<y?x:y;
}

int max(int x,int y,int z){
	int t1 = max(x,y);
	return max(t1,z);
}

int min(int x,int y,int z){
	int t1 = min(x,y);
	return min(t1,z);
}


class Solution {
public:
    int maxProduct(int A[], int n) {
    	if(n==1){
    		return A[0];
    	}
    	int global_max = A[0];
    	int local_max = A[0];
    	int local_min = A[0];
    	int local_max_copy;
    	for(int i=1;i<n;i++){
    		local_max_copy = local_max;
    		local_max = max(local_max * A[i],A[i],local_min * A[i]);
    		local_min = min(local_max_copy * A[i],A[i],local_min * A[i]);
    		global_max = max(global_max,local_max);
    	}
    	return global_max;
    }
};

int main(){
	int A[] = {2,3,-2,4};
	Solution s;
	int x = s.maxProduct(A, 4);
	cout << x;


}