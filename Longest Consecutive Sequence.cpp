#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
       	int max=0,local;
       	set<int> numbers = set<int>(num.begin(),num.end());
       	set<int>::iterator it;
       	int temp;
       	while(!numbers.empty()){
       		it = numbers.begin();
       		temp = *it;
       		numbers.erase(temp);
       		local=1;
       		while(numbers.find(++temp)!=numbers.end()){
       			local++;
       			numbers.erase(temp);
       		}
       		temp = *it;
       		while(numbers.find(--temp)!=numbers.end()){
       			local++;
       			numbers.erase(temp);
       		}
       		max = max>local?max : local;
       	}

    	return max;
    }
};

int main(){
	Solution s = Solution();
	int a[] = {0,3,7,2,5,8,4,6,0,1};
	vector<int> v = vector<int>(a,a+10);
	cout << s.longestConsecutive(v);
}