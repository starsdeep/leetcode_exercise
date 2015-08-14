#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
  		int i_size = dungeon.size();
  		int j_size = dungeon[0].size();
  		if(i_size==0 || j_size==0) return 0;
  		int** res = new int*[i_size];
		for(int i = 0; i < i_size; ++i){
    		res[i] = new int[j_size];      
		}
    	
    	res[0][0] = dungeon[0][0]<=0 ? -dungeon[0][0]+1: 0;

    	for(int j=1;j<j_size;j++){
    		res[0][j]+=res[0][j-1];
    		path_min = path_min<res[0][j]?path_min: res[0][j];
    	}
    	for(int i=1;i<i_size;i++){
    		res[i][0]+=res[i-1][0];
    		path_min = path_min<res[i][0]?path_min: res[i][0];
    	}
    	int from_up,from_left,min_up,min_left;
    	for(int i=1;i<i_size;i++){
    		for(int j=1;j<j_size;j++){
    			from_up = res[i-1][j]+dungeon[i][j];
    			from_left = res[i][j-1]+dungeon[i][j];
    			min_up = path_min[i-1][j]<from_up?path_min[i-1][j]: from_up;
    			min_left = path_min[i][j-1]<from_left?path_min[i][j-1]: from_left;
    			if(min) 
    		}
    	}
};


class Solution1 {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
    	vector<int> result;	    
    	if(dungeon.size()==0)
    		return 0;
    	help(0,0,dungeon,result,0,0);
    	int cost = *max_element(result.begin(),result.end());
    	if(cost>0)
    		return 0;
    	return -cost+1;

    }

    void help(int i, int j,vector<vector<int> >& dungeon, vector<int>&result, int path_min, int cost){
    	if(i==dungeon.size() || j==dungeon[0].size())
    		return;
    	cost += dungeon[i][j];
    	path_min = path_min<cost ? path_min: cost; 
    	if(i==dungeon.size()-1 && j==dungeon[0].size()-1){
    		result.push_back(path_min);
    		return;
    	}
    	help(i+1,j,dungeon,result,path_min,cost);
    	help(i,j+1,dungeon,result,path_min,cost);
    }
};

int main(){
	cout << "hello\n";
}
