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


class Solution{
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 1){
            result.push_back(num);
            return result;
        }
        
        vector<int> sub;
        sub.push_back(num[0]);
        result.push_back(sub);

        for(int i=1;i<num.size();i++){
            result = tool(result, num[i]); 
        }
        
        return result;

    }

    vector<vector<int> > tool(vector<vector<int> >& result, int k){
        //cout << num.size();
        //vector<vector<int> > v;
        vector<vector<int> > this_result;
        for(int i=0;i<result.size();i++){
            vector<vector<int> > tmp_result = process_single(result[i], k);
            this_result.insert(this_result.end(), tmp_result.begin(), tmp_result.end());
        }
        return this_result;
    }

    vector<vector<int> > process_single(vector<int>& v, int k){
        vector<vector<int> > result;
        for(int i=0;i<v.size();i++){
            if(v[i]==k){
                continue;
            }
            vector<int> tmp_v = vector<int>(v); 
            tmp_v.insert(tmp_v.begin() + i, k);
            result.push_back(tmp_v);
        }
        vector<int> tmp_v = vector<int>(v);
        tmp_v.insert(tmp_v.begin() + tmp_v.size(), k);
        result.push_back(tmp_v);
        return result;
    }

};





int main() {
    Solution s = Solution();
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    vector<vector<int> >x = s.permuteUnique(v);
    print_2d_vector(x);


}



