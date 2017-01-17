#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int> > m;
        
        for(int i=0;i<buildings.size();i++){
        	m[buildings[i][0]].push_back(buildings[i][2]);
        	m[buildings[i][1]].push_back(-buildings[i][2]);
        }
        priority_queue<int> heap;
        heap.push(0);
        map<int, int> counter;
        counter[0] = 1;
        vector<pair<int, int> > answer;
        for(map<int,vector<int> >::iterator it=m.begin();it!=m.end();it++){
        	cout << it->first << " ";
        	for(int h: it->second){
        		cout << h ;
        		if(h>0){
        			heap.push(h);
        			counter[h] = (counter.find(h)==counter.end()? 1: counter[h]+1);
        		}
        		else{
        			counter[-h] -= 1;
        		}
        	}
        	//cout << " " << heap.top()<< endl;
        	while(counter[heap.top()]==0) heap.pop();
        	if(answer.empty() || answer[answer.size()-1].first != it->first)
        		answer.push_back(make_pair(it->first, heap.top()));
        }
        return answer;
    }

    
};

int main(){
	vector<vector<int> > v;
	vector<int> vv = {0,1,3};
	v.push_back(vv);
	Solution s;
	s.getSkyline(v);

}