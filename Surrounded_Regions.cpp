#include<iostream>
#include<set>
#include<vector>

using namespace std;


class Solution {
public:
	int x_len;
	int y_len;
	bool needflip = true;
	set<int> onpoints;
	set<int> points;
	vector<vector<char>>* board;

	Solution(){	
	}

	

    void solve(vector<vector<char>> &board) {
        this->board = &board;
        y_len = board.size();
        if(y_len == 0)
        	return;
        x_len = board[0].size();
        if(x_len == 0)
        	return;
        cout << x_len;
        cout << y_len;
        cout << endl << endl;
        
        for(int x=0;x<x_len;++x){
        	for(int y=0;y<y_len;++y){
        		cout << "x:" << x << " y:" << y;
        		if(board[x][y] == 'O'){
        			//cout << x << " " << y << " ";
        			//cout<< getidx(x,y) << " ";
        			onpoints.insert(getidx(x,y)); 
        		}
        	}  
        }
       

        //cout << onpoints.size();
        cout << "t2";
        while(!onpoints.empty()){
        	points.clear();
        	needflip = true;
        	int p = *(onpoints.begin());
        	process_point(p,points);
        	if(needflip){
        		flip(points);
        	}
        }
    };

    void flip(set<int>& points){
    	int x;
    	int y;
    	for(set<int>::iterator it = points.begin();it!=points.end();++it){
    		x = getx(*it);
    		y = gety(*it);
    		(*board)[x][y] = 'X';
    	}
    	return;
    }

    void process_point(int idx, set<int>& points){
    	   	
    	cout << "idx:" << idx;
    	if(points.count(idx) > 0)
    		return;

    	points.insert(idx);
    	onpoints.erase(idx);

    	int x = getx(idx);
    	int y = gety(idx);

    	

    	if(onboard(x,y)){
    		cout << "test";
    		needflip = false;
    	}


    	if(left(x,y)>=0){
    		
    		process_point(getidx(x-1,y),points);
    	}
    	if(right(x,y)>=0)
    		process_point(getidx(x+1,y),points);
    	if(up(x,y)>=0)
    		process_point(getidx(x,y-1),points);
    	if(down(x,y)>=0)
    		process_point(getidx(x,y+1),points);			
    }

    bool onboard(int x, int y){
    	if(x==0 || x == x_len-1 || y==0 || y == y_len-1)
    		return true;
    	return false;
    }

    int left(int x, int y){
    	x = x-1;   
    	if(inboard(x,y) && (*board)[x][y] == 'O')
    		return getidx(x,y);
    	return -1;
    }

    int right(int x, int y){
    	x = x+1;
    	if(inboard(x,y) && (*board)[x][y] == 'O')
    		return getidx(x,y);
    	return -1;
    }

    int up(int x, int y){
    	y = y-1;
    	if(inboard(x,y) && (*board)[x][y] == 'O')
    		return getidx(x,y);
    	return -1;
    }

    int down(int x, int y){
    	y = y+1;
    	if(inboard(x,y) && (*board)[x][y] == 'O')
    		return getidx(x,y);
    	return -1;
    }

    bool inboard(int x, int y){
    	if(0<=x<x_len && 0<=y<y_len)
    		return true;
    	return false;

    }

    int getx(int idx){
    	return idx%x_len;
    }
    int gety(int idx){
    	return idx / x_len;
    }

    int getidx(int x, int y){
    	return y*x_len + x;
    }
};

int main(){
	
	vector<char> v1(3,'X');
	vector<char> v2;
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('X');

	vector<vector<char> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v1);
	
	Solution s;
	
	for(vector<vector<char> >::iterator it = v.begin(); it!=v.end(); ++it){
		for(vector<char>::iterator j = (*it).begin(); j!=(*it).end(); ++j){
			cout << *j << "";
		}
		cout << endl;
	}
	s.solve(v);

}
