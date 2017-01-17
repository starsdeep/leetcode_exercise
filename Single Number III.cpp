#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer;
        if(nums.size()==0) return answer;
        //first pass
        int temp = nums[0];
        for(int i=1;i<nums.size();i++){
        	temp ^= nums[i];
        }
        //find the bit
        int mask = 1;
        while((temp & mask)==0)
        	mask = mask << 1;
        //divide to 2 group
        int result1=0, result2=0;
        for(int i=0;i<nums.size();i++){
        	if((nums[i] & mask) == 0)
        		result1 ^= nums[i];
        	else 
        		result2 ^= nums[i];
        }
        answer.push_back(result1);
        answer.push_back(result2);
        return answer;
    }
};


int main(){

}