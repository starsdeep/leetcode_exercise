#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res = vector<int>(triangle.size(), 0);
        vector<int> temp;
        for(int level=0;level<triangle.size();level++){
        	temp = res;
        	res[0] = triangle[level][0] + temp[0];
        	res[level] = triangle[level][level] + temp[level-1];
        	for(int i=1;i<level;i++){
        		res[i] = min(temp[i-1],temp[i]) + triangle[level][i];
        	}
    	};
    	return *min_element(res.begin(), res.end());
    }
};

int main(){

}