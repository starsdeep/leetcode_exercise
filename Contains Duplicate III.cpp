#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(k<=0 || t<0) return false;
		int min_int = numeric_limits<int>::min();
		long temp=0, bucket_size=long(t)+1;
		map<long, long> bucket;
		for(int i=0;i<nums.size();i++){
			temp = (long(nums[i])-long(min_int))/bucket_size;
			if(bucket.find(temp)!=bucket.end() 
				|| (bucket.find(temp-1)!=bucket.end() && nums[i] - bucket[temp-1] <= t ) 
				|| (bucket.find(temp+1)!=bucket.end() && bucket[temp+1]-nums[i] <=t)
			) return true;

			bucket[temp] = long(nums[i]);

			if(bucket.size() > k){
				temp = (long(nums[i-k])-long(min_int))/bucket_size;
				bucket.erase(temp);
			}		
		}
		return false;
    }
};




int main(){
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<long>::max() << endl;
}