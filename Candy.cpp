#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

void print_array(int a[], int n){
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}

class Solution {
public:
    int candy(vector<int> &ratings) {
    	if(ratings.size()==0)
    		return 0;
    	int* res = new int[ratings.size()];
    	for(int i=0;i<ratings.size();i++)
    		res[i]=1;

    	int temp_i;
    	int i=0;
    	while(i<ratings.size()-1){
    		temp_i = i;
    		if(ratings[i]>ratings[i+1]){
    			while((i+1) < ratings.size() && ratings[i]>ratings[i+1]) i++;
    			process_desd_seg(res, temp_i, i);
    		}
    		i++;
    	}
    	res[ratings.size()-1] = 1;
    	int* candies = new int[ratings.size()];
    	candies[0]=res[0]>1?res[0]:1;
    	for(int i=1;i<ratings.size();i++){
    		if(ratings[i]>ratings[i-1])
    			candies[i] = candies[i-1]+1>res[i]?candies[i-1]+1:res[i];
    		else{
    			candies[i] = res[i];
    		}

    	}
    	int sum=0;
    	for(int i=0;i<ratings.size();i++)
    		sum+=candies[i];
    	delete[] candies;
    	delete[] res;
    	return sum;
    }
    void process_desd_seg(int* res, int left, int right){
    	int value = 1;
    	for(int i=right;i>=left;i--){
    		res[i]=value;
    		value++;
    	}
    	return;
    }
};

int main(){
	Solution s = Solution();
	//int A[] = {4,2,3,4,1};
	int A[] = {1,1,1};
	vector<int> v = vector<int>(A,A+3);
	cout << s.candy(v);
}
