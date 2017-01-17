/*
url:https://leetcode.com/problems/two-sum/
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort the nums and scan from head and tail 
        // using maps to remember the numbers position
        // you need two maps because maybe there are two same number added up to target.
        vector<int> res(2,1);
        unordered_map<int, int> um1,um2;
        for(int i = 0; i < nums.size(); i ++ ){
            if (um1.find(nums[i]) == um1.end())
            {
                um1[nums[i]] = i+1;
            }else if( um2.find(nums[i]) == um2.end() ){
                um2[nums[i]] = i+1;
            }
        }
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        while(l < r){
            if (nums[l]+nums[r] == target)
            {                
                res[0] = um1[nums[l]];

                if ( nums[l] == nums[r] )
                {
                    res[1] = um2[nums[r]];
                }else{
                    res[1] = um1[nums[r]];
                }
                sort(res.begin(), res.end());
                return res;
            }else if (nums[l] + nums[r] > target)
            {
                r--;
            }else{
                l++;
            }
        }

        return  res;
    }
};

int main(){
    Solution s = Solution();
    int a[] = {2, 7, 11, 15};
    vector<int> numbers =  vector<int>(a, a + sizeof(a) / sizeof(a[0]));
    int target = 9;
    vector<int> r = s.twoSum(numbers, target);
    cout << r[0] << " " << r[1] << endl;
}