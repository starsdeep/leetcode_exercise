#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int pivot = find_pivot(A,n);
        cout << "pivot: " << pivot << endl;
        if(pivot==0)
        	return find(A,0,n-1,target);
       
        return find(A,0,pivot-1,target) || find(A,pivot,n-1,target);
    }

	int find(int A[], int begin, int end, int target){
		int med = (begin+end)/2;
		if(target==A[med] || target==A[begin] || target==A[end])
			return true;
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
				return true;
		}
		return false;
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
    		else if(A[med] < A[begin]){
    			end = med;
    			med = (begin+end)/2;
    		}
            else{
                if(A[begin]==A[end]){
                    while(A[begin]==A[med]){
                        begin++;
                    }
                    while(A[end]==A[med]){
                        end--;
                    }
                    begin--;
                    end++;
                    if(begin==med && med==end)
                        return 0;
                    med = (begin + end)/2;
                    continue;
                }
                if(A[begin]<A[end]){
                    return 0;
                }
                else{
                    if(A[begin]==A[med]){
                        begin = med;
                        med = (begin+end)/2;
                        continue;
                    }
                    if(A[end]==A[med]){
                        end = med;
                        med = (begin+end)/2;
                        continue;
                    }
                }
            }
    	}
    	if(A[begin]<A[end])
    		return begin;
    	else
    		return end;
    }
};

int main(){
	int A[] = {1,1,1,1,1,1,1,3,1,1};
	Solution s = Solution();
	int target;
	while(cin>>target)
		cout << s.search(A, 10, target) << endl;
}