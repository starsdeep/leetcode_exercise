#include <map>
#include <iostream>
using namespace std;

void print_map(map<int,int> m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
    	cout << it->first << ": " << it->second << endl;
    }
    cout << endl;
}

void print_array(int a[], int n){
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}


class Solution {
public:
    int trap(vector<int>& height) {
              
    }
};


/*
class Solution {
public:
    int trap(int A[], int n) {
        if(n<=2)
        	return 0;
        int i=0;
        while(A[i]==0) i++;
        int left_value = A[i];
        int left_idx = i;
        int* container = new int[n];
        int total=0;
        int min=A[i];
        while((++i)<n){
        	if(A[i]>min){
        		// if(i==3){
        		// 	print_array(container,n);
        		// }
        		accumulate(container,total,left_value, A[i],left_idx,i);
        		min=A[i];
        		if(A[i]>=left_value){
        			left_idx = i;
        			left_value = A[i];		
        		}
        	}
        	container[i] = A[i];
        	min = min<container[i]?min:container[i];
        }
        delete[] container;
        return total;
    }

    void accumulate(int container[], int& total, int left_hight, int right_hight, int left_idx, int right_idx){
    	//cout << "in func" <<endl;
    	//cout << left_hight << right_hight << left_idx << right_idx << endl;
    	for(int i=left_idx+1;i<right_idx;i++){
    		if(container[i]<right_hight){
    			total += (left_hight - container[i])<(right_hight - container[i])?(left_hight - container[i]):(right_hight - container[i]);
    			container[i]=right_hight;
    		}
    	}
    }
};
*/

int main(){
	Solution s = Solution();
	int A[] = {4,9,4,5,3,2};
	cout << s.trap(A,6);
}


