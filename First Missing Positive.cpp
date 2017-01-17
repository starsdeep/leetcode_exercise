#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int i=0;
  		while(i<nums.size()){
  			if(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i])
  				swap(nums[nums[i]-1],nums[i]);
  			else
  				i++;
  		}
  		
  		for(int i=0;i<nums.size();i++){
  			if(nums[i]!=i+1)
  				return i+1;
  		}	      
  		return nums.size()+1;
    }
};

int main(){
	Solution s;
	vector<int> v = {3,4,-1,1};
	vector<int> v1 = {1};
	cout << s.firstMissingPositive(v);
}