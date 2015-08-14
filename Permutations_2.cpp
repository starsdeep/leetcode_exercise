/*
#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 1){
            result.push_back(num);
            return result;
        }
        vector<int> sub(&num[0], &num[result.size()-2]);
        tool(sub, num[num.size()-1]);
        return result;

    }

    vector<vector<int> > tool(vector<int>& num, int k){
        cout << num.size();
        vector<vector<int> > v;
        return v;
    }

};


int main() {
    //Solution s = Solution();
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //s.permuteUnique(v);
}
*/



