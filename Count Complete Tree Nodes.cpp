#include<iostream>
#include<stack>


using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    int countNodes(TreeNode* root) {
		if(root==NULL) return 0;
		int h = treeHeight(root);
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int h_left = treeHeight(left);
		int h_right = treeHeight(right);

		if(h_left==h_right)
			return (1<<h_left) + countNodes(right);
		else
			return countNodes(left) + (1<<h_right);

    }

    int treeHeight(TreeNode* root){
    	int h=0;
    	while(root){
    		h+=1;
    		root = root->left;
    	}
    	return h;
    }
};



int main(){




} 