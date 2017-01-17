#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
    	if(root==NULL) return;
    	vector<TreeNode*> res;
    	TreeNode* pre = root;
    	while(pre->left) pre=pre->left;
    	

    	help(root,pre,res);
    	cout << res[0]->val << "  " << res[1]->val << endl;

    	if(res.size()==2) swap(res[0]->val, res[1]->val);
    	if(res.size()==4) swap(res[0]->val, res[3]->val);

    	cout << res[0]->val << "  " << res[1]->val << endl;


    	return;
    }

    TreeNode* help(TreeNode* root, TreeNode* pre, vector<TreeNode*>& res){
    	//if(root==NULL) return root;
    	if(root->left){
    		pre = help(root->left, pre, res);	
    	}
    	if(pre->val > root->val){res.push_back(pre); res.push_back(root);}
    	TreeNode* ret = root;
    	if(root->right){
    		ret = help(root->right,root,res);
    	}
    	return ret;
    }
};

int main(){
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);

	Solution s;
	s.recoverTree(root);
}