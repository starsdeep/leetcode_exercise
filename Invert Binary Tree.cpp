#include<iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	help(root);
    	return root;

    }

    void help(TreeNode* root){
    	if(root==NULL)
    		return ;
    	TreeNode* temp = root->left;
    	root->left = root->right;
    	root->right = temp;
    	invertTree(root->left);
    	invertTree(root->right);
    }
};



int main(){

	

}