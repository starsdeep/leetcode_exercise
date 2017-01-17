#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	vector<vector<int> > answer;
    	if(nums.size()==0) return answer;
    	vector<int> temp;
    	sort(nums.begin(), nums.end());
    	help(answer, temp, nums);
    	return answer;    	
    }

    void help(vector<vector<int> >&answer, vector<int>temp, vector<int>nums){
    		if(nums.size()==0){
    			answer.push_back(temp);
    			return;
    		}
    		vector<int> num_copy;
    		for(int i=0;i<nums.size();i++){
    			if(i && nums[i-1]==nums[i])
    				continue;
    			num_copy = nums;
    			num_copy.erase(num_copy.begin()+i);
    			temp.push_back(nums[i]);
    			help(answer, temp, num_copy);
    			temp.pop_back();
    		}
    	}
};

int main(){

}