#include<iostream>
#include "/Users/starsdeep/workspace/common/cpp/source/LYK/simpio.h"
#include "/Users/starsdeep/workspace/common/cpp/source/LYK/vector.h"
using namespace std;

int main(){

    string s;
    getLine(cin,s);
    cout << s;
    
    Vector<int> v;
    v.append(1);
    cout << v.toString();
}
