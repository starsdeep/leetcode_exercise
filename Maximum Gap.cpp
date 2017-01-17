#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int max_value = *max_element(nums.begin(), nums.end());
        int min_value = *min_element(nums.begin(), nums.end());
        int bucket_size = int(ceil((max_value - min_value)*1.0 / (nums.size()-1)));

        vector<int> max_buckets(nums.size()-1, -1);
        vector<int> min_buckets(nums.size()-1, max_value+1);

        for(int i=0;i<nums.size();i++){
        	if(nums[i]==min_value || nums[i]==max_value)
        		continue;
        	int idx = (nums[i]-min_value) / bucket_size;
        	max_buckets[idx] = max(max_buckets[idx],nums[i]);
        	min_buckets[idx] = min(min_buckets[idx],nums[i]);
        }
        int prev = min_value;
        int max_gap = 0;
        for(int i=0;i<max_buckets.size();i++){
        	if(max_buckets[i] == -1)
        		continue;
        	cout << max_gap << ", "<< min_buckets[i] << " " << max_buckets[i] << " " << prev << endl;
        	max_gap = max(max_gap, min_buckets[i]-prev);
        	prev = max_buckets[i];
        }
        return max(max_gap,max_value-prev);
        
    }
};

int main(){
	vector<int> v = {3,6,9,1};
	Solution s;
	cout << s.maximumGap(v);
}