#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int size_y = matrix.size();
        int size_x = matrix[0].size();
        set<int> columns;
        for(int y=0;y<size_y;y++){
        	bool haszeros = false;
        	for(int x=0;x<size_x;x++){
        		if(matrix[y][x]==0){
        			columns.insert(x);
        			int t = x;
        			//while(t<size_x){matrix[y][t]=0;t++;}
        			if(!haszeros)
        				while(t>=0){matrix[y][t]=0;t--;}
        			haszeros = true;
        		}
        		else{
        			if(haszeros)
        				matrix[y][x] = 0;
        		}
        	}
        }
        for(set<int>::iterator it = columns.begin();it!=columns.end();++it){
        	for(int y=0;y<size_y;y++){
        		matrix[y][*it]=0;
        	}
        }
        return;
    }
};

int main(){
	cout << "hello";
}