#include <map>
#include <vector>
#include <iostream>

using namespace std;

void print_vector(vector<string> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> r;
		string temp;
		if(s.size()<10)
			return r;
		map<string, bool> m;
		for(int i=0;i+9<s.size();i++){
			temp = s.substr(i,10);
			if(m.find(temp)==m.end())
				m[temp]=false;
			else
				m[temp]=true;
		}
		for(map<string,bool>::iterator it=m.begin();it!=m.end();it++){
			if(it->second==true)
				r.push_back(it->first);
		}
		return r;
    }
};


int main(){
	Solution s = Solution();
	//vector<string> r = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	//print_vector(r);
	long l;
	
}
