 #include<iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	int s_size = s.size();
    	int t_size = t.size();

    	int res[s_size+1][t_size+1];

    	for(int i=0;i<s_size+1;i++){
    		for(int j=0;j<t_size+1;j++){
    			if(i==0 && j==0)
    				res[i][j] = 1;
    			else if(i==0)
    				res[i][j] = 0;
    			else if(j==0)
    				res[i][j] = 1;
    			else{
    				res[i][j] = (s[i-1]==t[j-1] ? res[i-1][j-1] + res[i-1][j]: res[i-1][j]);
    			}
    			cout << i << ", " << j << " || " << res[i][j] << endl; 
    		}
    	}
    	return res[s_size][t_size];
    }
};

int main(){
	string S = "r";
	string T = "a";
	Solution s = Solution();
	cout << s.numDistinct(S,T);

}