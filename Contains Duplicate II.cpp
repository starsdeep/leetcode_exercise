#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>  m;
        for(int i=0;i<nums.size();i++){
        	if(m.empty() || m.find(nums[i])==m.end()) m[nums[i]] = i;
        	else{
        		if(i-m[nums[i]] <= k)
        			return true;
        		m[nums[i]] = i;
        	}
        }
        return false;
    }
};

int main(){

}