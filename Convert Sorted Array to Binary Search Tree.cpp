#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return help(nums,0,nums.size()-1);   
    }

    TreeNode* help(vector<int>& nums, int start, int end){
    	if(start>end) return NULL;
    	int idx = (end+start)/2;
    	TreeNode* root = new TreeNode(nums[idx]);
    	root->left = help(nums, start, idx-1);
    	root->right = help(nums, idx+1, end);
    	return root;
    }


};

int main(){

}