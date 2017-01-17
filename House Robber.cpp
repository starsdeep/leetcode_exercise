#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  
    int rob(vector<int>& nums) {
    	int curr=0, pre=0;
    	for(int i=0;i<nums.size();i++){
    		int temp = max(nums[i] + pre, curr);
    		pre = curr;
    		curr = temp;
    	}
    	return curr;
    }

    int max(int a, int b){
    	return a>b?a:b;
    }
};


int main(){
	Solution s = Solution();
	vector<int> v = {2,1,1,2};
	cout << s.rob(v);
	 
}