#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        stack<pair<vector<int>,int> > temp;
        vector<int> t;
        result.push_back(t);
        if(S.size()==0)
        	return result;
        sort(S.begin(), S.end());
        int i=0;
        int currValue;
        while(i<S.size()){
        	t.clear();
        	currValue = S[i];
        	t.push_back(currValue);
        	result.push_back(t);
        	if(i==S.size()-1)
        		break;
        	temp.push(make_pair(t,i+1));
        	while(i<S.size() && currValue==S[++i]) ;
        }
        while(temp.size() >0 ){
        	temp = process(temp, result, S);
        }
        return result;
    }

    stack<pair<vector<int>, int> > process(stack<pair<vector<int>,int> >& temp, vector<vector<int> >& result, vector<int> &S){
    	stack<pair<vector<int>,int> > toProcess;
    	int currValue;
    	while(temp.size()>0){
    		pair<vector<int>, int> p = temp.top();
    		temp.pop();
    		vector<int> curr_list = p.first;
    		vector<int> temp_curr_list;
    		int begin = p.second;
    		int i = begin;
    		while(i<S.size()){
    			currValue = S[i];
    			temp_curr_list = curr_list;
    			temp_curr_list.push_back(S[i]);
    			result.push_back(temp_curr_list);
    			if(i==S.size()-1){
    				break;
    			}
    			toProcess.push(make_pair(temp_curr_list, i+1));
    			while(currValue==S[++i]) ;
    		}
    	}
    	return toProcess;
    }
};

int main(){
	cout << "hello" << endl;
	Solution s = Solution();
	vector<int> v = {1,2,3};
	vector<vector<int> > r;
	r = s.subsetsWithDup(v);
	print_2d_vector(r);
}




