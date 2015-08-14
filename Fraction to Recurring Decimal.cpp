#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>     


using namespace std;

void print_2d_vector(vector<vector<int> >x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
}

void print_vector(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}


class Solution {  
public:  
    string fractionToDecimal(int numerator, int denominator) {  
        if(numerator==0) return "0";  
        string result;  
        if(numerator<0 ^ denominator<0 ) result+='-';   //异或，numerator<0和denominator<0仅有一个为真  
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。  
        long long int n=numerator,d=denominator;  
        n=abs(n);d=abs(d);                
          
        result+=to_string(n/d);  //整数部分  
        long long int r=n%d;    //余数r  
        if(r==0) return result;  
        else result+='.';  
        //下面处理小数部分，用哈希表  
        unordered_map<int,int> map;  
        while(r){  
            //检查余数r是否在哈希表中，是的话则开始循环了  
            if(map.find(r)!=map.end()){  
                result.insert(map[r],1,'(');   //http://www.cplusplus.com/reference/string/basic_string/insert/  
                result+=')';  
                break;  
            }  
            map[r]=result.size();    //这个余数对应于result的哪个位置  
            //正常运算  
            r*=10;  
            result+=to_string(r/d);  
            r=r%d;  
        }  
        rint
        return result;
    }  
};  




// problem, the precision problem of float representation



// class Solution {
// public:

// 	string num2str(double a){
// 		stringstream ss;
// 		ss << setprecision(40) << a;
// 		string s;
// 		ss >> s;
// 		return s;
// 	}

//     string fractionToDecimal(int numerator, int denominator) {
// 		string result;
// 		string temp;
// 		double n = numerator * 1.0;
// 		double d = denominator * 1.0;
// 		temp = to_string(n * 1.0 /d);

// 		return temp;

// 		int i=0;
// 		while(true){
// 			if(i==temp.size() || temp[i]=='.')
// 				break;
// 			i++;
// 		}
// 		if(i==temp.size())
// 			return temp;
// 		//process the digits behind '.'
// 		map<char, vector<int>> m;
// 		vector<int> t;
// 		while((++i)<temp.size()){
// 			if(m.find(temp[i]) == m.end()){
// 				t.clear();
// 				t.push_back(i);
// 				m[temp[i]] = t;
// 			}
// 			else{
// 				t = m[temp[i]];
// 				for(int j=0;j<t.size();j++){
// 					if(match(temp,t[j],i)){
// 						result = temp.substr(0, t[j]);
// 						result += '(' + temp.substr(t[j], i-t[j]) + ')';
// 						return result;
// 					}
// 					m[temp[i]].push_back(i);
// 				}
// 			}
// 		}
// 		return temp;
//     }

//     bool match(string& temp, int idx1, int idx2){
//     	int len = idx2 - idx1;
//     	if(idx2 + len == temp.size())
//     		return temp.substr(idx1, len) == temp.substr(idx2, len);
//     	if(idx2 + len + len <= temp.size())
//     		return temp.substr(idx1, len) == temp.substr(idx2, len) && temp.substr(idx2, len) == temp.substr(idx2+len, len);
//     	return false;
//     }
// };




int main(){
	
	Solution s = Solution();
	//cout << s.fractionToDecimal(1,17);
	cout << s.num2str(1.0 / 17.0);
	


}


