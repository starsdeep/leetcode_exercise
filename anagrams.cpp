#include<iostream>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> m;
        vector<string> sorted_strs;
        vector<string> result;
        string tmp;
        for(vector<string>::iterator it=strs.begin(); it!=strs.end();++it){
            tmp = *it;            
            sort(tmp.begin(),tmp.end());           
            sorted_strs.push_back(tmp);
            if(m.count(tmp)){
                m[tmp]++;
            }
            else{
                m.insert(pair<string,int>(tmp,1));
            }
        }
        for(int i=0;i<sorted_strs.size();++i){
            if(m[sorted_strs[i]] > 1){
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> s1 = {"string","srting","fsjgl"};
    vector<string> s2 = s.anagrams(s1);

    for(int i=0;i<s2.size();++i)
        cout << s2[i] << "   ";
 
}