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
    int kthSmallest(TreeNode* root, int k) {
   		int count=1, res;
   		return traverse(root, k, count, res);
    }

    bool traverse(TreeNode* root, int k, int& count, int& res){
    	if(root->left)
    		if(traverse(root->left, k, count, res))
    			return true;
  	
    	if(count == k){
    		count++;
    		res = root->val;
    		return true;
    	}
    	count++;

    	if(root->right)
    		if(traverse(root->right, k, count, res))
    			return true;
    	return false;
    }
};

int main(){

}