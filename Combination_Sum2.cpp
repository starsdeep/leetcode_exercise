#include <iostream>
#include <vector>
#include <set>
#include <sstream>
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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
  		vector<int> candidate_sum;
  		vector<vector<int> > candidate;
  		vector<vector<int> > result;

  		set<string> result_set;
  		set<string> candidate_set;

  		if(num.size()==0){
  			return result;
  		}
  		sort(num.begin(), num.end());
  		vector<int> temp;
  		string temp_str;
  		for(int i=0;i<num.size();i++){
  			temp.clear();
  			if(num[i]==target){
  				temp.push_back(num[i]);
  				temp_str = vec2str(temp);
  				if(result_set.find(temp_str) == result_set.end()){
  					result.push_back(temp);
  					result_set.insert(temp_str);
  				}
  			}
  			else if(num[i] < target){
  				help(target, num[i], result, result_set, candidate, candidate_set, candidate_sum);
  			}
  			else;
  		}
  		return result;
    }

    void help(int target, int num, vector<vector<int> >& result, set<string>& result_set, vector<vector<int> >& candidate, set<string>& candidate_set,vector<int>& candidate_sum){
    	int i;
    	int s = candidate_sum.size();
    	vector<int> temp;
    	string temp_str;
    	
    	temp.push_back(num);
    	temp_str = vec2str(temp);
    	if(candidate_set.find(temp_str)==candidate_set.end()){
    		candidate_set.insert(temp_str);
    		candidate.push_back(temp);
    		candidate_sum.push_back(num);
    	}
    	for(i=0;i<s;i++){
    		if(candidate_sum[i]+num==target){
    			temp = candidate[i];
    			temp.push_back(num);
    			temp_str = vec2str(temp);
    			if(result_set.find(temp_str)==result_set.end()){
    				result.push_back(temp);
    				result_set.insert(temp_str);
    				candidate.erase(candidate.begin() + i);
    				candidate_sum.erase(candidate_sum.begin() + i);
    				i--;
    				s--;
    			}
    		}
    		else if(candidate_sum[i]+num<target){
    			temp = candidate[i];
    			temp.push_back(num);
    			temp_str = vec2str(temp);
    			if(candidate_set.find(temp_str)==candidate_set.end()){
    				candidate_set.insert(temp_str);
    				candidate.push_back(temp);
    				candidate_sum.push_back(candidate_sum[i] + num);
    			}
    		}
    		else;
    	}
    }

    string vec2str(vector<int>& v){
    	string s;
    	for(int i=0;i<v.size();i++){
    		s += int2str(v[i]);
    	}
    	return s;
    }

    string int2str(int i){
    	stringstream ss;
    	string s;
    	ss << i;
    	ss >> s;
    	return s;
    }

};




int main(){
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(1);
	
	
	vector<vector<int> >r;
	Solution s= Solution();
	r = s.combinationSum2(t1, 2);
	print_2d_vector(r);

}