#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.size()==0) return 0;
    	if(nums.size()==1) return nums[0];
    	return max(rob_normal(nums, 0, nums.size()-2), rob_normal(nums, 1, nums.size()-1));
    }

    int rob_normal(vector<int>& nums, int start, int end){
    	int pre=0, curr=0;
    	int temp;
    	for(int i=start;i<=end;i++){
    		temp = max(nums[i]+pre, curr);
    		pre = curr;
    		curr = temp;
    	}
    	return curr;
    }

};

int main(){
Solution s = Solution();
	vector<int> v = {2,1,1,2};
	cout << s.rob(v);
}