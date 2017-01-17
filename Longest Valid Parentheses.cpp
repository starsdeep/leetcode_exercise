#include <iostream>
#include <stack>

using namespace std;

class Solution1 {
public:
    int longestValidParentheses(string s) {
    	int max_len = 0;
    	int temp_len;
    	if(s.size()==0) return max_len;

    	stack<int> Stack;

    	for(int i=0;i<s.size();i++){
    		if(s[i]=='(')
    			Stack.push(-1);
    		else{
    			if(!Stack.empty())
    				reduce(Stack, max_len);
    		}
    	}

        update(max_len, Stack);
        
    	return max_len;
    }

    
    void reduce_int(stack<int>& s, int value){
        if(!s.empty() && s.top()>0)
            s.top() += value;
        else
            s.push(value);
    }
    
    void reduce(stack<int>& s, int& max_len){
        if (s.top() > 0 && s.size()>=2) {
            int temp = s.top();
            s.pop();s.pop();
            reduce_int(s, temp+2);
        }
        else if(s.top() < 0){
            s.pop();
            reduce_int(s, 2);
        }
        else{
            update(max_len,s);
        }
    }
    
    void update(int& max_len, stack<int>& s){
        int curr = 0;
        while(!s.empty()){
            if(s.top()>0){
                curr += s.top();
                max_len = max(max_len, curr);
            }
            else{
                curr = 0;
            }
            s.pop();
        }
    }


};




/*
int main(){

	Solution s;
	string ss =")()())()()(";
	cout << s.longestValidParentheses(ss);

}*/