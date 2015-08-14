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
	int min_Depth = 0;
    int minDepth(TreeNode *root) {
    	if(root == NULL){
    		return min_Depth;
    	}
        go_deep(root, 1);
        return min_Depth;
    }
    void go_deep(TreeNode *node, int curr_deepth){
    	if(min_Depth>0 && curr_deepth >= min_Depth)
    		return;
    	if(node->left==NULL && node->right==NULL){
    		min_Depth = curr_deepth;
    		return;
    	}
    	else{
    		if(node->left)
    			go_deep(node->left, curr_deepth+1);
    		if(node->right)
    			go_deep(node->right, curr_deepth+1);
    	}
    }
};

int main(){
	Solution s = Solution();
	TreeNode * root = new TreeNode(4);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(23); 

	cout << s.minDepth(root);

}