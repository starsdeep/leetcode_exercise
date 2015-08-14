#include <vector>
#include <set>
#include <iostream>
#include <numeric>

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
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        vector<int> item;
        
        if(n==0 || k==0)
        	return r;
        vector<int> v(n);
		iota(v.begin(), v.end(), 1);
   
        if(n==k){
        	r.push_back(v);
        	return r;
        }
        for(int i=1;i<=n;i++){
        	item.push_back(i);
        	help(k, n, i+1, item, r);
        	item.pop_back();
        	
        }
        return r;
    }

    void help(int k, int n, int start, vector<int> item, vector<vector<int> >& r){

    	if(item.size()==k){
    		r.push_back(item);
    		return;
    	}
    	for(int i=start;i<=n;i++){
    		item.push_back(i);
    		help(k,n,i+1,item,r);
    		item.pop_back();
    	}
    }
};

int main(){
	//cout << "hello";
	Solution s= Solution();
	vector<vector<int> > v;
	v = s.combine(4,2);
	print_2d_vector(v);
}