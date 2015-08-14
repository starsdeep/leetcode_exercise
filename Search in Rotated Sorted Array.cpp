#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int pivot = find_pivot(A,n);
        //cout << "pivot: " << pivot << endl;
        if(pivot==0)
        	return find(A,0,n-1,target);
        int r1 = find(A,0,pivot-1,target);
        int r2 = find(A,pivot,n-1,target);
        //cout << r2;
        return r1>r2 ? r1: r2;
    }

	int find(int A[], int begin, int end, int target){
		int med = (begin+end)/2;
		if(target==A[med])
			return med;
		if(target==A[begin])
			return begin;
		if(target==A[end])
			return end;
		while(end-begin>=2){
			if(target<A[med]){
				end = med;
				med = (begin+end)/2;
			}
			else if(target>A[med]){
				begin = med;
				med = (begin+end)/2;
			}
			else
				return med;
		}
		return -1;
	}

    int find_pivot(int A[], int n){
    	int begin=0, end=n-1, med=(begin+end)/2;
    	//cout << "in func" << endl;
    	while(end-begin>=2){
    		//cout << med << endl;
    		if(A[med]>A[begin]){
    			begin = med;
    			med = (begin+end)/2;
    		}
    		else{
    			end = med;
    			med = (begin+end)/2;
    		}
    	}
    	if(A[begin]<A[end])
    		return begin;
    	else
    		return end;
    }
};

int main(){
	int A[] = {4, 5, 6, 7, 0, 1, 2};
	Solution s = Solution();
	int target;
	while(cin>>target)
		cout << s.search(A, 7, target) << endl;
}