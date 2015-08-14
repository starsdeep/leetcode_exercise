#include <iostream>

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
        	return true;
        return is_equal(root->left,root->right);
    }

    bool is_equal(TreeNode* node1, TreeNode* node2){
    	if(node1==NULL && node2==NULL)
    		return true;
    	else if(node1==NULL && node2!=NULL || node1!=NULL && node2==NULL)
    		return false;
    	else
    		if(node1->val == node2->val)
    			return is_equal(node1->left,node2->right) && is_equal(node1->right,node2->left);
    		else
    			return false;
    }

};


int main(){


}