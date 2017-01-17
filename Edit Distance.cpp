#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0 && word2.size()==0) return 0;
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();

        int res[word1.size()+1][word2.size()+1];
        //initialization
        res[0][0] = 0;
        for(int i=1;i<word1.size()+1;i++)
        	res[i][0] = i;
        for(int i=1;i<word2.size()+1;i++)
        	res[0][i] = i;

        for(int i=1;i<word1.size()+1;i++){
        	for(int j=1;j<word2.size()+1;j++){
        		int temp = 0;
        		if(word1[i-1]!=word2[j-1])
        			temp = 1;
        		res[i][j] = min_3(1+res[i-1][j],1+res[i][j-1],temp+res[i-1][j-1]);
        	}
        }
        return res[word1.size()][word2.size()];
    }

    int min_3(int a,int b,int c){
    	return min(min(a,b),min(b,c));
    }
};

int main(){
	Solution s = Solution();
	string s1 = "abb";
	string s2 = "acb";

	cout << s.minDistance(s1,s2);
}