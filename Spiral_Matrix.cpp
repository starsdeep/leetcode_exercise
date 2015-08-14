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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> result;
    	if(matrix.size()==0)
    		return result;
        int sizeY = matrix[0].size();
        int sizeX = matrix.size();
        bool **visited = new bool*[sizeX];
		for(int i = 0; i < sizeX; ++i) {
    		visited[i] = new bool[sizeY];
    	}
    	for(int x=0;x<sizeX;x++){
    		for(int y=0;y<sizeY;y++){
    			visited[x][y] = false;
    		}
    	}
    	visited[0][0] = true;
    	result.push_back(matrix[0][0]);
    	int pos_x = 0;
    	int pos_y = 0;
    	int temp_x = pos_x;
    	int temp_y = pos_y;
        while(true){
        	if(go_right(pos_x, pos_y, sizeX, sizeY, visited, matrix, result)==false)
        		break;
        	if(go_down(pos_x, pos_y, sizeX, sizeY, visited, matrix, result)==false)
        		break;
        	if(go_left(pos_x, pos_y, sizeX, sizeY, visited, matrix, result)==false)
        		break;
        	if(go_up(pos_x, pos_y, sizeX, sizeY, visited, matrix, result)==false)
        		break;
        	if(temp_x==pos_x && temp_y==pos_y)
        		break;
        	else{
        		temp_x = pos_x;
        		temp_y = pos_y;
        	}
    	}
    	return result;
    }

    bool go_right(int & pos_x, int & pos_y, int sizeX, int sizeY, bool** visited, vector<vector<int> > matrix, vector<int>& result){
    	if(!in_region(pos_x, pos_y+1, sizeX, sizeY))
    		return true;

    	if(visited[pos_x][pos_y+1])
    		return false;
    	while(in_region(pos_x,++pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==false){
    		result.push_back(matrix[pos_x][pos_y]);
    		visited[pos_x][pos_y] = true;
    	}
    	pos_y--;
    	return true;
    }

    bool go_down(int & pos_x, int & pos_y, int sizeX, int sizeY, bool** visited, vector<vector<int> > matrix, vector<int>& result){
    	if(!in_region(pos_x+1, pos_y, sizeX, sizeY))
    		return true;
    	if(visited[pos_x+1][pos_y])
    		return false;
    	while(in_region(++pos_x,pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==false){
    		result.push_back(matrix[pos_x][pos_y]);
    		visited[pos_x][pos_y] = true;
    	}
    	pos_x--;
    	return true;
    }

    bool go_left(int & pos_x, int & pos_y, int sizeX, int sizeY, bool** visited, vector<vector<int> > matrix, vector<int>& result){
    	if(!in_region(pos_x, pos_y-1, sizeX, sizeY))
    		return true;
    	if(visited[pos_x][pos_y-1])
    		return false;
    	while(in_region(pos_x,--pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==false){
    		result.push_back(matrix[pos_x][pos_y]);
    		visited[pos_x][pos_y] = true;
    	}
    	pos_y++;
    	return true;
    }

    bool go_up(int & pos_x, int & pos_y, int sizeX, int sizeY, bool** visited, vector<vector<int> > matrix, vector<int>& result){
    	if(!in_region(pos_x-1, pos_y, sizeX, sizeY))
    		return true;
    	if(visited[pos_x-1][pos_y])
    		return false;
    	while(in_region(--pos_x,pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==false){
    		result.push_back(matrix[pos_x][pos_y]);
    		visited[pos_x][pos_y] = true;
    	}
    	pos_x++;
    	return true;
    }

    bool in_region(int x, int y, int sizeX, int sizeY){
    	return x>=0 && x<sizeX && y>=0 && y<sizeY;
    }
};



int main(){
	vector<int> t1;
	t1.push_back(1);
	//t1.push_back(2);

	vector<int> t2;
	t2.push_back(3);
	t2.push_back(4);

	vector<vector<int> > t3;
	t3.push_back(t1);
	//t3.push_back(t2);

	vector<int> result;
	Solution s = Solution();
	result = s.spiralOrder(t3);
	print_vector(result);
}


