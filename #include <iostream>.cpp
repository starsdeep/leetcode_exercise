#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums){
		int n = nums.size();
		int result = n;
		int i=0;
		for(int num: nums){
			result ^= num;
			result ^= (i++);
		}
		return result;
	}

};

int main(){
	vector<int> v = {0};
	Solution s;
	cout << s.missingNumber(v);
}