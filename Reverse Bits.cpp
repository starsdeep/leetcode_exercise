#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t mask1 = 1;
		uint32_t mask2 = (1 << 31);
		uint32_t result = 0;
		for(int i=0;i<32;i++){
			cout << n < " " << mask1 << " " << mask2 << endl;
			if(n & mask1){
				result = result | mask2;
			}
			mask2 = mask2 >> 1;
			mask1 = mask1 << 1;
		}
		return result;
    }
};

int main(){
	Solution s = Solution();
	cout << s.reverseBits(2);

}


