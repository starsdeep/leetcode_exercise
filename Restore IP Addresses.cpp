#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<string> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> result;        
    	string item;
    	help(s,0,item,0,result);
    	return result;
    }

    void help(string& s, int start, string item, int num, vector<string>& result){
    	if(num==3){
    		string sub = s.substr(start,s.size()-start);
    		if(is_okay(sub)){
    			item += sub;
    			result.push_back(item);
    		}
    		return;
    	}
    	string temp;
    	int min_idx = s.size()<(start+3)?s.size(): start+3;
    	for(int i=start;i<min_idx;i++){
    		if(is_okay(s.substr(start,i-start+1))){
    			temp = item+s.substr(start,i-start+1) + ".";
    			help(s,i+1,temp,num+1,result);
    	}

    	}
    }

    bool is_okay(string s){

    	return s.size()==1 || (s.size()==2 && s[0]!='0') || (s.size()==3 && s[0]!='0' && s <= "255");
    }

};



int main(){
	cout << "hello"<<endl;
	Solution s = Solution();
	vector<string> r = s.restoreIpAddresses("010010");
	print_vector(r);
}