#include<iostream>
#include<algorithm>
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
    int maxPathSum(TreeNode* root) {
    	int global_max = root->val;
    	maxSum(global_max, root);
    	return global_max;    
    }

    int maxSum(int& global_max, TreeNode* root){
    	if(root==NULL) return 0;
    	int leftSum = maxSum(global_max, root->left);
    	int rightSum = maxSum(global_max, root->right);
    	vector<int> list = {root->val, root->val+leftSum, root->val+rightSum, root->val+leftSum+rightSum};
    	int local_max = *max_element(list.begin(),list.end());
    	global_max = global_max>local_max ? global_max: local_max;
    	return local_max;
    }
};

int main(){

}