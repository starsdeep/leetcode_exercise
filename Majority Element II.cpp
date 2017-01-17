#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
 		int count1 = 0, count2 = 0;		
 		int value1 = 0, value2 = 1; // can be any integer, since num1, num2 can are 0
 		for(int i=0;i<nums.size();i++){
 			if(nums[i]==value1)
 				count1++;
 			else if(nums[i]==value2)
 				count2++;
 			else if(count1==0){
 				value1 = nums[i];
 				count1 = 1;
 			}
 			else if(count2==0){
 				value2 = nums[i];
 				count2 = 1;
 			}
 			else{
 				count1--;
 				count2--;
 			}
 		}
 		vector<int> result;
 		if(count(nums.begin(),nums.end(),value1) > nums.size()/3 ) result.push_back(value1);
 		if(count(nums.begin(),nums.end(),value2) > nums.size()/3 ) result.push_back(value2);

 		return result;
    }
};


int main(){

}