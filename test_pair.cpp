#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;
int main(){
	stack<pair<vector<int>, int>> s;
	pair<vector<int>, int> p;
	vector<int> v;
	p.first = v;
	p.second =2;
	s.push(p);
	cout << "hello";
}