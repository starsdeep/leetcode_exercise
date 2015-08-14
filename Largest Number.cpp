#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_vector(vector<string> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> res;
        for(int i=0;i<num.size();i++){
        	res.push_back(to_string(num[i]));
        }
        sort(res.rbegin(),res.rend(), my_sort);
        print_vector(res);
        if(res[0]=="0")
        	return "0";
        string s;
        for(int i=0;i<num.size();i++){
        	s+=res[i];
        }
        return s;
    }

    static bool my_sort(const string& left, const string& right){
    	int s, y, diff;
        diff = left.size()-right.size();
        if(diff==0)
    		return left<right;
    	else if(diff<0){
            if(right.substr(0,left.size())==left){
                return right < (right.substr(left.size(),-diff) + left);
            }
            return left < right.substr(0,left.size());
        }
        else{
            if(left.substr(0,right.size())==right){
                return (left.substr(right.size(),diff) + right) < left;
            }
            return left.substr(0,right.size()) < right;
        }
    }

};


int main(){
	int a[] = {824,938,1399,5607,6973,5703,9609,4398,8247};
	int b[] = {121,12};
    vector<int> v = vector<int>(b,b+2);
	Solution s = Solution();
	cout << s.largestNumber(v);
	//cout<<s.my_sort("30","3");
    
}