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
    int minPathSum(vector<vector<int> > &grid) {
        int size_x = grid[0].size();
        int size_y = grid.size();

        int ** res = new int*[size_y];
        for(int y=0;y<size_y;y++){
        	res[y] = new int[size_x];
        }
        res[0][0] = grid[0][0];
        for(int x=1;x<size_x;x++){
        	res[0][x] = res[0][x-1] + grid[0][x];
        }
        for(int y=1;y<size_y;y++){
        	res[y][0] = res[y-1][0] + grid[y][0];
        }

        for(int y=1;y<size_y;y++){
        	for(int x=1;x<size_x;x++){
        		int m = res[y-1][x] < res[y][x-1] ? res[y-1][x]: res[y][x-1];
        		res[y][x] = grid[y][x] + m;
        	}
        }
        //cout << res[0][0] << res[0][1] << res[1][0] << res[1][1];
        int r = res[size_y-1][size_x-1];
        //print_2d_vector(res);
        for(int y=0;y<size_y;y++) {
    		delete [] res[y];
		}
		delete [] res;
		return r;
    }
};

int main(){
	vector<int> t = vector<int>(2,0);
	t[0] = 1;
	t[1] = 2;
	vector<vector<int> > v;
	v.push_back(t);
	t[0] = 1;
	t[1] = 1;
	v.push_back(t);
	
	Solution s = Solution();
	cout << s.minPathSum(v);
}