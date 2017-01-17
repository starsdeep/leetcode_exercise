#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int answer = 0;
    	for(int i=0;i<grid.size();i++){
    		for(int j=0;j<grid[0].size();j++){
    			if(grid[i][j]=='1'){
    				answer++;
    				flood(grid,i,j);
    			}
    		}
    	}
    	return answer;
    }

    void flood(vector<vector<char> >& grid, int x, int y){
    	if(inRange(grid,x,y) && grid[x][y]=='1'){
    		grid[x][y] = '#';
    		flood(grid,x+1,y);
    		flood(grid,x-1,y);
    		flood(grid,x,y+1);
    		flood(grid,x,y-1);
    	}
    }
    
    bool inRange(vector<vector<char> >& grid, int x, int y){
    	return x>=0 && x<grid.size() && y>=0 && y<grid[0].size();
    }

};

int main(){

}