#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()<=1) return 0;
    	int buy1,sell1,buy2,sell2;
    	buy1 = sell1 = prices[0];
    	int candidate_buy = -1;
    	for(int i=1;i<prices.size();i++){
    		if(prices[i] < candidate_buy)
    			candidate_buy = prices[i];
    		else if(prices[i]-candidate_buy > min(sell1-buy1, sell2-buy2)){
    			if(sell1-buy1)
    		}

    		else if(prices[i] > min(sell1, sell2)){
    			if(sell1 < sell2)
    				sell1 = prices[i];
    			else 
    				sell2 = prices[i];
    		}
    		else if(prices[i] - candidate_buy > min(sell1,sell2) - max(buy1,buy2)){
    			if(buy1>buy2)
    				buy1 = candidate_buy;
    			else
    				buy2 = candidate_buy;
    			if(sell1<sell2)
    				sell1 = prices[i];
    			else
    				sell2 = prices[i];
    		}
    		else
    			;
    	}
    	return sell1+sell2-buy1-buy2;
    }
};

int main(){
	Solution s = Solution();
	vector<int> v = {1,2,3,1};
	cout << s.maxProfit(v); 
}