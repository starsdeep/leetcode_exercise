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
    void flatten(TreeNode *root) {
  		if(root==NULL)
  			return;
  		TreeNode * right = root->right;
  		TreeNode * tail = root;
  		if(root->left)
  			tail = help(tail, root->left);
  		if(right)
  			tail = help(tail, right);
    }

    TreeNode* help(TreeNode* root, TreeNode* sub){
    	root->left = NULL;
    	root->right = sub;
    	TreeNode* tail = root->right;
    	TreeNode* right = sub->right;
    	if(sub->left)
    		tail = help(tail, sub->left);
    	if(right)
    		tail = help(tail, right);
    	return tail;
    }
};


int main(){
	cout << "hello";
}
