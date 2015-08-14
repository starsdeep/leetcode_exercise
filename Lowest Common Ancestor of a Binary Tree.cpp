#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  		if(root==NULL)
  			return root;
  		if(root==p || root==q)
  			return root;
  		TreeNode* left = lowestCommonAncestor(root->left, p, q);
  		TreeNode* right = lowestCommonAncestor(root->right, p, q);

  		if(left && right==NULL)
  			return left;
  		else if(left==NULL && right)
  			return right;
  		else
  			return root;
    }
};


int main(){

}