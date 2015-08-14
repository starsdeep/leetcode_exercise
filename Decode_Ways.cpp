#include <iostream>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        if(s == "")
        	return 0;
        int joint = 0;
        int sep = 0;
    	if(s[0]=='0')
    		return 0;
    	else 
    		sep = 1;

    	s = preprocess(s);
    	int size = s.size();
    	int temp_sep;
    	if(size == 0)
    		return 0;
        for(int i=1;i<size;i++){
        	//cout << "iteration:" << i << endl;
        	//cout << joint << "  "<< sep;
        	//cout << "-----------------"<<endl;
        	if(s[i-1]=='a'){
        		sep = sep + joint;
        		joint = 0;
        		continue;
        	}
        	if(s[i]=='a'){
        		continue;
        	}
        	int digit1 = int(s[i]-'0');
        	int digit2 = int(s[i-1]-'0');
        	// can joint
        	if(digit2*10 + digit1 <= 26){
        		temp_sep = sep;
        		sep = joint + temp_sep;
        		joint = temp_sep;
        	}
        	// cant not
        	else{
        		sep = joint + sep;
        		joint = 0;
        	}
        }
        return sep + joint;
       
    }

    string preprocess(string s){
    	
    	if(s.size()>1){
    		string r;
    		r += s[0];
    		for(int i=1;i<s.size();i++){
    			if(s[i]=='0'){
    				if(r[r.size()-1]=='1' || r[r.size()-1]=='2'){
    					r[r.size()-1]='a';
    					continue;
    				}
    				else{
    					return "";
    				}
    			}
    			r += s[i];
    		}
    		return r;
    	}
    	return s;

    }

};



int main(){
	Solution s = Solution();
	cout << s.numDecodings("1212");

	return 0;
}


