#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;

        int size_x = matrix.size();
        int size_y = matrix[0].size();

        int x = 0;
        int y = matrix[0].size()-1;
    	
        while(x<size_x && y>=0){
        	if(target > matrix[x][y]) x++;
        	else if(target < matrix[x][y]) y--;
        	else return true;
        }
        return false;
    }
};

int main(){

}