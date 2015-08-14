#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> result;
    	help(result,root,0); 
    	return result;    
    }

    void help(vector<int>& result, TreeNode* root, int deepth){
    	if(root==NULL) return;
    	if(result.size()==deepth)
    		result.push_back(root->val);
    	help(result,root->right,deepth+1);
    	help(result,root->left,deepth+1);
    }
};

int main(){

}