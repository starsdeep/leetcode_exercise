#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size()<=1) return 0;
		vector<int> diff = vector<int>(prices.size()-1);
		for(int i=1;i<prices.size();i++){
			diff[i-1] = prices[i] - prices[i-1];
		}
		int result = 0;
		for(int i=0;i<diff.size();i++){
			if(diff[i]>0)
				result+=diff[i];
		}
		return result;
    }
};

int main(){
	Solution s = Solution();
	vector<int> v = {1,2,3,1};
	cout << s.maxProfit(v);

}