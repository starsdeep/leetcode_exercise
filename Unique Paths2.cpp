#include <iostream>
#include <vector>

using namespace std;
void print_2d_vector(vector<vector<int> >x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
}

void print_vector(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int size_y = obstacleGrid.size();
        int size_x = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1)
        	return 0;
        else
        	obstacleGrid[0][0]=1;
        bool flag = true;
        for(int x=1;x<size_x;x++){
        	if(obstacleGrid[0][x] == 1)
        		flag = false;
        	if(flag)
        		obstacleGrid[0][x] = 1;
        	else
        		obstacleGrid[0][x] = 0;
        }
        flag = true;
        for(int y=1;y<size_y;y++){
        	if(obstacleGrid[y][0] == 1)
        		flag = false;
        	if(flag)
        		obstacleGrid[y][0] = 1;
        	else
        		obstacleGrid[y][0] = 0;
        }
        
        for(int y=1;y<size_y;y++){
        	for(int x=1;x<size_x;x++){
        		if(obstacleGrid[y][x]==1){
        			obstacleGrid[y][x]=0;
        		}
        		else{
        			obstacleGrid[y][x] = obstacleGrid[y-1][x] + obstacleGrid[y][x-1];
        		}
        	}
        }
        //print_2d_vector(obstacleGrid);
        return obstacleGrid[size_y-1][size_x-1];
    }
};

int main(){
	vector<int> t = vector<int>(3,0);
	vector<vector<int> > v;
	v.push_back(t);
	t[1] = 1;
	v.push_back(t);
	t[1] = 0;
	v.push_back(t);

	Solution s = Solution();
	cout << s.uniquePathsWithObstacles(v);
}


