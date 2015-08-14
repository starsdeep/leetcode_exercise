#include <vector>
#include <iostream>
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
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > r;
        vector<int> item;
        r.push_back(item);
        if(S.size()==0)
        	return r;
        sort(s.begin(),S.end());
        for(int k=1;k<=S.size();k++){
        	for(int i=0;i<S.size();i++){
        		item.push_back(S[i]);
        		help(k,i+1,S,item,r);
        		item.pop_back();
        	}
        }
        return r;
    }

    void help(int k, int start, vector<int>& S, vector<int> item, vector<vector<int> >& r){
    	if(item.size()==k){
    		r.push_back(item);
    		return;
    	}
    	for(int i=start;i<S.size();i++){
    		item.push_back(S[i]);
    		help(k,i+1,S,item,r);
    		item.pop_back();
    	}
    }
};

int main(){
	Solution s = Solution();
	vector<int> v = vector<int>(3);
	iota(v.begin(),v.end(),1);
	vector<vector<int> > r;
	r = s.subsets(v);
	print_2d_vector(r);

}