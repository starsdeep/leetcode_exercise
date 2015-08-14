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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> item;
        if(candidates.size()==0){
        	return result;
        }
        sort(candidates.begin(), candidates.end());
        help(target, 0, candidates, item, result);
        return result;
    }


    void help(int target, int start, vector<int>& candidates, vector<int> item, vector<vector<int> >& result){
    	if(target<0)
    		return;
    	if(target==0){
    		result.push_back(item);
    		return;
    	}
    	for(int i=start;i<candidates.size();i++){
    		if(i>0 && candidates[i-1]==candidates[i])
    			continue;
    		item.push_back(candidates[i]);
    		help(target-candidates[i], i, candidates, item, result);
    		item.erase(item.begin()+item.size()-1);
    	}
    }
};

int main(){
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	
	
	vector<vector<int> >r;
	Solution s= Solution();
	r = s.combinationSum(t1, 2);
	print_2d_vector(r);

}