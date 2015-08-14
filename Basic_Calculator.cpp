#include<iostream>
#include"stack.h"

using namespace std;

// -1 (, -2 ), -3 +, -4 -

class Solution {
public:
    int calculate(string s) {
        Stack<int> mystack;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c==' ')
                continue;
            else if(c=='('){
                mystack.push(-1);
            }
            else if(c=='+'){
                mystack.push(-3);
            }
            else if(c=='-'){
                mystack.push(-4);
            }
            else if(c>='0' && c<='9'){
                int num = readInt(s, i);
                reduce(mystack, num);
            }
            else if(c==')'){
                int value = mystack.top(); mystack.pop(); mystack.pop();
                reduce(mystack, value);
            }
            else
                cout << "error";

            //cout << "stack: " << mystack.toString();
        }
        return mystack.top();
    }

    int readInt(string& s, int& i){
        int num=0;
        while(s[i]>='0' && s[i]<='9'){
            num = num*10 + int(s[i]-'0');
            i++;
        }
        i--;
        return num;
    }
    
    void reduce(Stack<int>& s, int num){
        if(s.isEmpty()){
            s.push(num);
            return; 
        }
        int last1 = s.top();
        if(last1==-3 || last1==-4){
            s.pop();
            int last2 = s.top(); s.pop();
            s.push(last1==-3 ? last2+num :last2-num);

        }
        else
            s.push(num);
    }
};

int main(){
    Solution s = Solution();
    cout << s.calculate("1 + 1") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)");
}
