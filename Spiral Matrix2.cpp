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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > visited;

        if(n==0)
        	return visited;

        for(int i=0;i<n;i++){
        	vector<int> temp = vector<int>(n,0);
        	visited.push_back(temp);
        }

        int pos_x = 0;
    	int pos_y = 0;
    	int temp_x = pos_x;
    	int temp_y = pos_y;
    	int sizeX = n;
    	int sizeY = n;
    	int i=1;
    	visited[0][0] = 1;
    	i++;
        while(true){
        	if(go_right(pos_x, pos_y, sizeX, sizeY, visited,i)==false)
        		break;
        	if(go_down(pos_x, pos_y, sizeX, sizeY, visited,i)==false)
        		break;
        	if(go_left(pos_x, pos_y, sizeX, sizeY, visited,i)==false)
        		break;
        	if(go_up(pos_x, pos_y, sizeX, sizeY, visited,i)==false)
        		break;
        	if(temp_x==pos_x && temp_y==pos_y)
        		break;
        	else{
        		temp_x = pos_x;
        		temp_y = pos_y;
        	}
    	}
    	return visited;
    }

    bool go_right(int & pos_x, int & pos_y, int sizeX, int sizeY, vector<vector<int> >& visited, int& a){
    	if(!in_region(pos_x, pos_y+1, sizeX, sizeY))
    		return true;

    	if(visited[pos_x][pos_y+1])
    		return false;
    	while(in_region(pos_x,++pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==0){
    		visited[pos_x][pos_y] = a++;
    	}
    	pos_y--;
    	return true;
    }

    bool go_down(int & pos_x, int & pos_y, int sizeX, int sizeY,  vector<vector<int> >& visited, int& a){
    	if(!in_region(pos_x+1, pos_y, sizeX, sizeY))
    		return true;
    	if(visited[pos_x+1][pos_y])
    		return false;
    	while(in_region(++pos_x,pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==0){
    		visited[pos_x][pos_y] = a++;
    	}
    	pos_x--;
    	return true;
    }

    bool go_left(int & pos_x, int & pos_y, int sizeX, int sizeY, vector<vector<int> >& visited, int& a){
    	if(!in_region(pos_x, pos_y-1, sizeX, sizeY))
    		return true;
    	if(visited[pos_x][pos_y-1])
    		return false;
    	while(in_region(pos_x,--pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==0){
    		visited[pos_x][pos_y] = a++;
    	}
    	pos_y++;
    	return true;
    }

    bool go_up(int & pos_x, int & pos_y, int sizeX, int sizeY, vector<vector<int> >& visited, int& a){
    	if(!in_region(pos_x-1, pos_y, sizeX, sizeY))
    		return true;
    	if(visited[pos_x-1][pos_y])
    		return false;
    	while(in_region(--pos_x,pos_y,sizeX,sizeY) && visited[pos_x][pos_y]==0){
    		visited[pos_x][pos_y] = a++;
    	}
    	pos_x++;
    	return true;
    }

    bool in_region(int x, int y, int sizeX, int sizeY){
    	return x>=0 && x<sizeX && y>=0 && y<sizeY;
    }
};

int main(){
	
	vector<vector<int> > result;
	Solution s = Solution();
	result = s.generateMatrix(5);
	print_2d_vector(result);
}

