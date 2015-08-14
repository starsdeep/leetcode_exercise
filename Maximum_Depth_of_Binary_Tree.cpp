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
	int max = 0;
    /*
    int maxDepth(TreeNode *root) {
    	if(root)
        	good_deep(root,1);
        return max;
    }
    */

    void good_deep(TreeNode* node, int currDeepth){
    	if(node->left==NULL && node->right==NULL){
    		if(currDeepth>max)
    			max = currDeepth;
    		return;
    	}
    	if(node->left)
    		good_deep(node->left, currDeepth+1);
    	if(node->right)
    		good_deep(node->right, currDeepth+1);
    }

    int maxDepth(TreeNode * root){
    	return get_max_deep(root);
    }

    void get_max_deep(TreeNode* root){
    	if(root==NULL)
    		return 0;
    	int left = get_max_deep(root->left);
    	int right = get_max_deep(root->right);
    	return left>right?left+1:right+1;
    }
    



};

int main(){

	cout << "hello";
}

