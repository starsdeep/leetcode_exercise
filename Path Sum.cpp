#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
 		return root && help(root, sum, 0);       
    }

    bool help(TreeNode* root, int sum, int pathSum){
    	if(root==NULL) return false;
    	if(root->left==NULL && root->right==NULL) return sum==(pathSum+root->val);
    	return help(root->left, sum, pathSum+root->val) || help(root->right, sum, pathSum+root->val); 
    }

};

int main(){

}