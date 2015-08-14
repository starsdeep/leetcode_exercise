#include<iostream>
#include<sstream>
#include <limits> 

using namespace std;

class Solution {
public:
    int reverse(int x) {
    int xx = x;
    if(x<0){
        xx = -x;
    }
    string s;
    stringstream ss;
    ss << xx;
    ss >> s;
    s = reverse(s);
    ss.clear();
    ss << s;
    int result;
    double y;
    ss >> y;
    if(x<0)
        y = -y;
    if(inRange(y))
        result = int(y);
    else
        result = 0;
    return result;
    }
    
    string reverse(string& s){
        string r;
        for(int i=s.size()-1;i>=0;i--){
            r += s[i];
        }
        return r;
    }

    bool inRange(double y){
        return y < numeric_limits<int>::max() && y > numeric_limits<int>::min();
    }

};



int main(){
    int x;
    Solution s;
    
    while(cin >> x){
        cout << "input is: " << x << endl;
        cout << "output is: " << s.reverse(x) << endl;
    }
    

}





