#include <iostream>
#include <vector>
#include <set>
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


class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > answer;
        vector<int> item;
        vector<bool> used = vector<bool>(nums.size(),false);
        help(answer,item,nums,used);
        return answer;
    }
    
    void help(vector<vector<int> >& answer, vector<int>item, vector<int>& nums, vector<bool>& used){
        if(item.size()==nums.size()){
            answer.push_back(item);
            return;
        }
        //set<int> s;
        for(int i=0;i<nums.size();i++){
            if(used[i]==true || (i>0 && used[i-1]==false && nums[i]==nums[i-1]))
                continue;
            
            item.push_back(nums[i]);
            used[i] = true;
            //s.insert(nums[i]);
            help(answer,item,nums,used);
            item.pop_back();
            used[i] = false;
        }
    }
};




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
    Solution1 s = Solution1();
    vector<int> v;
    v.push_back(1);

    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    vector<vector<int> >x = s.permute(v);
    print_2d_vector(x);
    cout<<x.size();


}



