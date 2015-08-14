#include <iostream>

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:

	bool is_balanced = true;
    bool isBalanced(TreeNode *root) {
  		if(root == NULL)
  			return true;
  		if(go_deep(root, 1) == -1)
  			return false;
  		return true;
  		
    }
    int go_deep(TreeNode* node, int currDeepth){
    	int left = currDeepth;
    	int right = currDeepth;
    	if(node->left==NULL && node->right==NULL)
    		return currDeepth;
    	if(node->left!=NULL)
    		left = go_deep(node->left, currDeepth+1);
    	if(node->right!=NULL)
    		right = go_deep(node->right, currDeepth+1);
    	if(left == -1 || right == -1)
    		return -1;
    	if(right-left>1 || left-right>1)
    		return -1;
    	return left>right?left:right;
    }
    

};


int main(){
	Solution s = Solution();
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->left->right = new TreeNode(6);

	cout << s.isBalanced(root);


}



