#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		//set<int> s(numbers.begin(),numbers.end());
		map<int,int> m;
		vector<int> r(2);
		for(int i=0;i<numbers.size();i++){
			if(numbers[i]*2==target){
				if(m.find(numbers[i])!=m.end()){
					r[0] = m[numbers[i]], r[1] = i+1;
					return r;
				}
				m[numbers[i]] = i+1;
			}
			else
				if(m.find(numbers[i])==m.end())
					m[numbers[i]]=i+1;
		}
		
		for(int i=0;i<numbers.size();i++){
			if(numbers[i]*2==target)
				continue;
			if(m.find(target-numbers[i])!=m.end()){
				r[0] = i+1;
				r[1] = m[target-numbers[i]];
				sort(r.begin(),r.end());
				return r;
			}
		}
    }
};

int main(){
	int a[] = {3,2,4};
	vector<int> v = vector<int>(a,a+3);
	Solution s = Solution();
	vector<int> r = s.twoSum(v, 6);
	cout << r[0] << " " << r[1] << endl;
}