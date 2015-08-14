#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int maxArea(vector<int> &height) {
        if(height.size()<=1)
        	return 0;
        int global_max=0, local_max = 0, min_height;
        for(int i=1;i<height.size()-1;i++){
        	local_max = 0;
        	for(int j=0;j+i<height.size();j++){
        		min_height = height[j] < height[j+i] ? height[j]: height[j+i];
        		local_max = local_max > min_height*i ? local_max: min_height*i;
        	}
        	global_max = global_max > local_max ? global_max: local_max;
        }
        return global_max;
    }
};

//剪枝，仍然是N方
class Solution2 {
public:
    int maxArea(vector<int> &height) {
        if(height.size()<=1)
        	return 0;
        int global_max=0, value = 0, left_heihgt=0, right_height=0, min_height;
        for(int left=0;left<height.size()-1;left++){
        	if(height[left]<left_heihgt)
        		continue;
        	for(int right=height.size()-1;right>left;right--){
        		if(height[right]<right_height)
        			continue;
        		min_height = height[left] < height[right] ? height[left]: height[right];
        		value = min_height * (right-left);
        		if(value>global_max){
        			global_max = value;
        			left_heihgt = height[left];
        			right_height = height[right];
        		}
        	}
        }
        return global_max;
    }
};

//O(n)
class Solution {
public:
    int maxArea(vector<int> &height) {
    	int max=0, left=0,right=height.size()-1;
        while(right>left){
        	while(right>left && height[left]<=height[right]){
        		if(max < height[left]*(right-left))
        			max = height[left]*(right-left);
        		left++;		
        	}
        	while(right>left && height[right]<=height[left]){
        		if(max < height[right]*(right-left))
        			max = height[right]*(right-left);	       		
        		right--;
        	}
        }
        return max;
    }
};



int main(){
	Solution s = Solution();
	int A[] = {2,2};
	vector<int> v = vector<int>(A, A+2);
	cout << s.maxArea(v);
}