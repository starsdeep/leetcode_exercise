#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
  		if(num.size() == 0 )
  			return 0;
  		if(num[0] < num[num.size()-1])
  			return num[0];
  		if(num.size() == 1)
  			return num[0];
  		int left_idx = 0;
  		int right_idx = num.size() - 1;
  		int mid;

  		while(true){
  			if(right_idx - left_idx == 1)
  				break;
  			if(num[left_idx] == num[right_idx]){
  				return linear_find(num,left_idx,right_idx);
  				break;
  			}
  			mid = (left_idx + right_idx) / 2;
  			if(num[mid] >= num[left_idx])
  				left_idx = mid;
  			else
  				right_idx = mid;
  		}
  		return num[right_idx];
    }

    int linear_find(vector<int> &num,int left_idx, int right_idx){
    	int m = num[left_idx];
    	int i = left_idx;
    	while(i < right_idx){
    		if(num[i] < m)
    			return num[i];
    		i++;
    	}
    	return m;
    }

};

int main(){
	Solution s;
	vector<int> num = {4, 5, 6, 7, 0, 1, 2};
	cout << s.findMin(num);
}