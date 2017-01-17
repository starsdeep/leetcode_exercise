#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int start = 0, end = -1, sum = 0;
		int answer = 0;
		if(nums.size()==0) return answer;
		//cout << end;
		//cout << nums.size();
		int l = nums.size();
		while(end < l){
			if(sum<s){
				end++;
				sum += nums[end];
			}
			else{
				if(answer == 0)
					answer = end-start+1;
				else 
					answer = min(answer, end-start+1);
				sum -= nums[start];
				start++;
				if(start>end)
				    end++;
			}
			//cout << start << ":" << end << endl;
			//cout << "answer: " << answer << endl;
			//cout << "sum: " << sum << endl;
			//cout << "-----------------------\n";  
		}
		return answer;
    }
};	

int main(){
	Solution s;
	vector<int> v = {1,4,4};
	cout << "hello\n";
	int x = s.minSubArrayLen(4, v);
}