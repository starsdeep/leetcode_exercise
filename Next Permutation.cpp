#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vector(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	if(num.size()==0 || num.size()==1)
    		return;
        int i = num.size()-2;
        while(i>=0){
        	if(num[i]<num[i+1])
        		break;
        	i--;
        }
        if(i==-1){
        	reverse(num.begin(),num.end());
        }
        else{
        	int t = num[i];
        	int j = num.size()-1;
        	while(num[j]<=t) j--;
        	num[i] = num[j];
        	num[j] = t;
        	reverse(num.begin()+i+1,num.end());
        }
    }
};


int main(){
	//cout << "hello";
	int A[] = {1,5,1};
	vector<int> v = vector<int>(A,A+3);
	Solution s = Solution();
	s.nextPermutation(v);
	print_vector(v);
}
