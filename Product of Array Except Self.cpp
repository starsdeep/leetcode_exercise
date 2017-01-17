// 貌似找规律的题目，很难想到哇
/*
	根据答案，得到的规律，要得到O(n)，必定是连续的解决问题，并且所以肯定是要利用连乘。然后一看规律，才能想到。总是还是很闹想的。

*/



#include <iostream>
#include <vector>
#include <vector.h>

using namespace std;

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> dp;
    	int acc = nums[1] * nums[0];
    	dp.push_back(nums[1]);
    	dp.push_back(nums[0]);

    	for(int i=2;i<nums.size();i++){
    		for(int j=0;j<i;j++){
    			dp[j] *= nums[i];
    		}
    		dp.push_back(acc);
    		acc *= nums[i];
    		
    	}
    	return dp;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result = vector<int>(nums.size(),1);

        int temp = 1;
        for(int i=1;i<nums.size();i++){
        	temp *= nums[i-1];
        	result[i] = temp;
        }
        temp = 1;
        for(int i=nums.size()-2;i>=0;i--){
        	temp *= nums[i+1];
        	result[i] *= temp;
        }
        return result;
    }
};

int main(){
	Solution s;
	vector<int> nums = {1,2,3,4};
	Vector<int> v = Vector<int>(s.productExceptSelf(nums));
	cout << v.toString();
}