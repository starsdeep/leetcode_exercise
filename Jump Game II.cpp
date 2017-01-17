#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
  		int count = 0;
  		int maxJump = 0;
  		if(nums.size()<=1) return 0;
  		maxJump = nums[0];
  		int i=0;
  		while(i<nums.size()){
  			if(i + maxJump >= nums.size()-1)
  				return ++count;
  			int nextJump = 0;
  			int nextPosition = 0;
  			for(int j=i+1;j<=i+maxJump;j++){
  				if(nums[j]+j>nextJump){
  					nextJump = nums[j]+j;
  					nextPosition = j;
  				}
  			}
  			count++;
  			maxJump = nextJump - nextPosition;
  			i = nextPosition;
  		}
  	}    
};

int main(){
	vector<int> v = {3,0,2,0,3};
	Solution s;
	cout << s.jump(v);
}