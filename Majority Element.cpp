#include<iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int num = 1;
    	int value = nums[0];
    	for(int i=1;i<nums.size();i++){
    		if(nums[i] == value)
    			num++;
    		else{
    			if(num==0){
    				value = nums[i];
    				num = 1;
    			}
    			else
    				num--;
    		}
    	}
    	return value;
    }
};


int main(){

}