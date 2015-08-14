#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void pirnt_map(map<int,int>& m){
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++)
		cout << it->first << "=>" << it->second << std::endl;
	cout << endl;
}

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2) return 0;
        map<int,int> res;
        set<int> inserted;
        int diff;
        for(int i=0;i<num.size();i++){
        	if(inserted.find(num[i])!=inserted.end()) continue;
        	inserted.insert(num[i]);
        	if(res.find(num[i])==res.end()){
        		res[num[i]+1] = -1;
        		res[num[i]-1] = 1;
        	}
        	else{
        		int diff = res[num[i]];
        		if(res[num[i]]>0){
        			res[num[i]-1] = diff+1;
        			res[num[i]+diff+1] = res[num[i]+diff+1]-1;
        			res.erase(num[i]);
        		}
        		else{
        			res[num[i]+1] = diff-1;
        			res[num[i]+diff-1] = res[num[i]+diff-1]+1;
        			res.erase(num[i]);
        		}
        	}
        }
        pirnt_map(res);
        auto pr = max_element(res.begin(), res.end(),
      	[](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
        return pr->second;
    }
};

int main(){
	//out << "hello";
	Solution s = Solution();
	int a[] = {1,1000000};
	vector<int> v = vector<int>(a,a+2);
	cout << s.maximumGap(v);
}