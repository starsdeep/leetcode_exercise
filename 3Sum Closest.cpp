#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int sum = nums[0] + nums[1] + nums[2];
    	for(int i=0;i<nums.size()-2;i++){
    		int left = i+1;
    		int right = nums.size()-1;
    		while(left<right){
    			int tmp = nums[i] + nums[left] + nums[right];
    			if(abs(tmp-target) < abs(sum-target)) sum = tmp;
    			if(tmp<target) left++;
    			else if(tmp>target) right--;
    			else{
    				return target;
    			}
    		}
    	}
        return sum;
    }
};

int main(){
	Solution s = Solution();
	vector<int> v = {-1,2,1,-4};
	cout << s.threeSumClosest(v, 1);

}