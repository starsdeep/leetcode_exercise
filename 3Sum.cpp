#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*

因为存在重复，用multiset 很烦，所以需求其他方法

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		if(nums.size()<=2) return result;
		sort(nums.begin(), nums.end());
		multiset<int > s(nums.begin(), nums.end());
		for(int i=0;i<nums.size()-2;i++){
			for(int j=i+1;j<nums.size()-1;j++){
				temp_s = s;
				temp_s.
				if(s.find(-nums[start]-nums[i])!=s.end()){
					vector<int> v = {nums[start], nums[i], -nums[start]-nums[i]};
					result.push_back(v);
			}
		}
		}


    }

    void help(vector<vector<int> >result, vector<int>& nums, multiset<int> s, int start){
		
	}


};
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
		if(nums.size()<=2) return result;
		sort(nums.begin(), nums.end());

		for(int i=0;i<nums.size()-2;i++){
			int left = i+1;
			int right = nums.size()-1;
			while(left < right){
				int sum = nums[left] + nums[right];
				if(nums[i]+sum < 0) left++;
				else if(nums[i] + sum > 0) right--;
				else{
					vector<int> v = {nums[i],nums[left],nums[right]};
					result.push_back(v);
					while(left<right && nums[left]==v[1]) left++;
					while(left<right && nums[right]==v[2]) right--;
				}
			}
			while(i+1<nums.size()-2 && nums[i+1]==nums[i]) i++;
		}
		return result;
    }

};



int main(){



}