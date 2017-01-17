#include <iostream>
#include <queue>
#include <vector>
#include <vector.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   		vector<int> result;
   		if(nums.empty()) return result;
   		for(int i=0;i<k;i++)
   			push(nums[i]);
   		result.push_back(maxValue());
   		for(int i=k;i<nums.size();i++){
   			pop();
   			push(nums[i]);
   			result.push_back(maxValue());
   		}
   		return result;
    }

private:
	queue<int> s1;
	deque<int> s2;

	void push(int v){
		s1.push(v);
		while(!s2.empty() && v>s2.back()) s2.pop_back();
		s2.push_back(v);
	}

	void pop(){
		if(s1.empty()) return;
		if(s1.front()==s2.front()) s2.pop_front();
		s1.pop();
	}

	int maxValue(){
		return s2.front();
	}
		
};

int main(){
	Solution s;
	vector<int> v = {1,3,-1,-3,5,3,6,7};
	vector<int> r = s.maxSlidingWindow(v,3);
	Vector<int> result = Vector<int>(r);
	cout << result.toString();



}