#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
    		return "0";
        
    	bool sign1 = num1[0]=='-' ? false: true;
    	bool sign2 = num1[0]=='-' ? false: true;
    	bool sing = (sign1 == sign2);
    	if(!sign1)
    		num1 = num1.substr(1, num1.size()-2);
    	if(!sign2)
    		num2 = num2.substr(1, num2.size()-2);

    	string max = num1;
    	string min = num2;
    	if(num1.size()<num2.size()){
    		max = num2;
    		min = num1;
    	}
    	int digit;
    	string zeros;
    	string result;
    	string temp;
    	for(int i=min.size()-1;i>=0;--i){
    		digit = int(min[i]-'0');
    		if(digit!=0){
    			temp = multiply_single(max, digit) + zeros;
    			cout << result << "  " << temp << endl;
    			result = add(result, temp);
    		}
    		zeros += "0";
    	}

		return result;
    }


    string add(string num1, string num2){
    	string result;
    	string max = num1;
    	string min = num2;
    	if(num1.size()<num2.size()){
    		max = num2;
    		min = num1;
    	}
    	int max_size = max.size();
    	int min_size = min.size();
    	int sum, curr_digit, offset=0;
    	int idx=1;
    	while(min_size-idx >=0) {
    		sum = int(max[max_size-idx]-'0') + int(min[min_size-idx]-'0')+offset;
			curr_digit = sum % 10;
			offset = sum / 10;
			result = char('0' + char(curr_digit)) + result;
			idx++;
    	}
    	idx = max.size()-min.size()-1;
    	while(idx>=0){
    		sum = int(max[idx]-'0')+offset;
			curr_digit = sum % 10;
			offset = sum / 10;
			result = char('0' + char(curr_digit)) + result;
			idx--;
    	}
    	if(offset!=0)
    		result = char('0' + char(offset)) + result;
    	return result;
    }

    string multiply_single(string s, int digit){
    	string result;
    	int idx = s.size()-1;
    	int curr_digit, product, offset=0;
    	while(idx>=0){
			product = digit * int(s[idx]-'0');;
			curr_digit = product % 10 + offset;
			offset = product / 10;
			result = char('0' + char(curr_digit)) + result;
			//cout << digit1 << " " << digit2 << " " << curr_digit << " " << offset << " " << result;
			idx--;
		}
		if(offset!=0)
			result = char('0' + char(offset)) + result;
		return result;
    }

};

int main(){
	Solution s = Solution();
	cout << s.add("6888","49200");
	//cout << s.multiply("6888", "49200");
}

