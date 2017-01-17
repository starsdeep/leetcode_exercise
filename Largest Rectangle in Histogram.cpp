#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
		if(height.size()==0) return 0;
		int maxArea=0;
		height.push_back(0);
		stack<int> s;

		int i=0, n=height.size();
		while(i<n){
			if(s.empty() || height[i]>height[s.top()]) s.push(i++);
			else{
				int h = height[s.top()]; s.pop();
				int j = s.empty() ? -1: s.top();
				maxArea = max(maxArea, h*(i-j-1));
			}
		}
		return maxArea;
    }
};

int main(){

}