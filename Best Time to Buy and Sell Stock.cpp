#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if(prices.size()<=1)
    		return 0;
    	int max_profit = 0, buy_price=prices[0], canditate_buy=buy_price;
    	for(int i=0;i<prices.size();i++){
    		if(prices[i]-canditate_buy > max_profit){
    			buy_price = canditate_buy;
    			max_profit = prices[i]-buy_price;
    			continue;
    		}
    		if(prices[i]<canditate_buy)
    			canditate_buy = prices[i];
    	}
    	return max_profit;
    }
};

int main(){
	Solution s = Solution();
	int A[] = {1,2};
	vector<int> p = vector<int>(A, A+2);
	cout << s.maxProfit(p);
}