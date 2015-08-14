#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <cctype>
#include <cstdlib>


using namespace std;

void print_vector(vector<string> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		if(tokens.size()==1)
			return str2int(tokens[0]);
		stack<int> s;
		s.push(str2int(tokens[0])), s.push(str2int(tokens[1]));
		int i = 2, t1,t2,t3;
		while(i<tokens.size()){
			if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/"){
				t1 = s.top(),s.pop();
				t2 = s.top(),s.pop();
				if(tokens[i]=="+") t3 = t2+t1;
				else if(tokens[i]=="-") t3 = t2-t1;
				else if(tokens[i]=="*") t3 = t2*t1;
				else if(tokens[i]=="/") t3 = t2/t1;
				else cout << "error"<<endl;
				s.push(t3);
			}
			else{
				s.push(str2int(tokens[i]));
			}
			i++;
		}
		return s.top();
    }
    int str2int(string s){
    	stringstream ss;
    	int r;
    	ss<<s;
    	ss>>r;
    	return r;
    }
};

int main(){
	cout << "hello"<<endl;
	string s[] = {"2", "1", "+", "3", "*"};
	vector<string> v = vector<string>(s,s+5);
	print_vector(v);
	Solution ss = Solution();
	cout << ss.evalRPN(v);



}