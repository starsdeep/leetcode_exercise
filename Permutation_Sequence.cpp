#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>

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
    string getPermutation(int n, int k) {
        vector<int> v(n);
		iota(v.begin(), v.end(), 1);
		string s;

		print_vector(v);

		while(v.size()>0){
			s += int2str(get_digit(v, k));
		}
		return s;
    }

    string int2str(int t){
    	stringstream ss;
    	string s;
    	ss << t;
    	ss >> s;
    	return s;
    }

    int get_digit(vector<int>& v, int& k){
    	int len = v.size();
    	if(len == 1){
    		int value = v[0];
    		v.erase(v.begin()+0);
    		return value;
    	}
    	int p = get_permutation_num(len-1);
    	int index = int(ceil(k * 1.0 / p));
    	
    	int value = v[index-1];
    	cout << "vector is:";
    	print_vector(v);
    	//cout << "p:" << p << "  k:" << k << "  index :" << index << endl;
    	v.erase(v.begin() + index - 1);
    	k = k - (index-1)*p;
    	return value;
    }

    int get_permutation_num(int n){
    	int r=1;
    	for(int i=1;i<n+1;i++){
    		r *= i;
    	}
    	return r;
    }

};

int main(){
	Solution s = Solution();
	//s.getPermutation(3,3);
	cout << s.getPermutation(4,1);
}