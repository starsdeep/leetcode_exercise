#include <iostream>
#include <vector>

using namespace std;

void print_2d_vector(vector<vector<int> >x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
}

void print_vector(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
  		int begin=0,end=n-1,median=(begin+end)/2;    
  		vector<int> r = vector<int>(2,-1);  
  		if(n==0 || (n==1 && A[0]!=target))
  			return r;

  		while(true){
  			if(A[median]==target){
  				begin = median;
  				end = median;
  				while(begin>=0 && A[begin]==target) begin--;
  				while(end<n && A[end]==target) end++;
  				r[0] = begin + 1;
  				r[1] = end - 1;
  				return r;
  			}
  			else if(A[median] < target){
  				if(A[median+1] > target || median==n-1)
  					return r; 
  				begin = median;
  				if(median == (end + begin) / 2)
  					median++;
  				else
  					median = (end + begin) / 2;

  			}
  			else{
  				if(median==0)
  					return r;
  				end = median;
  				median = (begin + end) / 2;
  			}
  		}
  		return r;
    }
    
};

int main(){
	int A[] = {2,2};
	Solution s = Solution();
	print_vector(s.searchRange(A,2,3));
}