#include <iostream>

#include <vector>

using namespace std;

void print_vector(vector<int>& v){
	cout << "[ ";
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << " ]\n"; 
}

void print_2d_vector(vector<vector<int> >& v){
	cout << "[ \n";
	for(int i=0;i<v.size();i++){
		print_vector(v[i]);
	}
	cout << "]\n";
}



class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	int temp;
    	int N = matrix.size();
    	for(int i=0;N-2*i>0;i++){
    		process(matrix,N-2*i,i);
    	}    
    }

    void process(vector<vector<int> >& matrix, int N, int allign){
    	if(N==1)
    		return;
    	for(int j=0;j<N-1;j++){
    		int k=4;
    		int i = 0;
    		int prev;
    		int curr;
    		while((k--) > 0){
    			int temp_i = i;
    			int temp_j = j;
    			i = temp_j;
    			j = N-1-temp_i;
    			if(k==3)
    				prev = matrix[temp_i+allign][temp_j+allign];
    			curr = matrix[i+allign][j+allign];
    			matrix[i+allign][j+allign] = prev;
    			prev = curr;
    		}
    	}
    }
};

int main(){
	Solution s = Solution();
	vector<int> v1 = {1,2};
	vector<int> v2 = {3,4};
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	s.rotate(v);
	print_2d_vector(v);
	return 0;
}