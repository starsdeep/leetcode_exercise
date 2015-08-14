#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int size_y = matrix.size();
        int size_x = matrix[0].size();

        int y=0;
        while(y<size_y){
        	if(matrix[y][0]==target)
        		return true;
        	if(matrix[y][0]>target){
        		y--;
        		break;
        	}
        	y++;
        }
        if(y==size_y)
        	y--;
        if(y<0)
        	return false;
        vector<int> t = matrix[y];
        std::vector<int>::iterator low;
        low=lower_bound (t.begin(), t.end(), target);
        if(low-t.begin()==t.size())
        	return false;
        if(*low == target)
        	return true;
        return false;
    }
};


int main(){
	int a1[] = {1,2};
	int a2[] = {3,4};
	vector<int> v1 = vector<int>(a1,a1+2);
	vector<int> v2 = vector<int>(a2,a2+2);
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	Solution s = Solution();
	cout << s.searchMatrix(v,3);
}