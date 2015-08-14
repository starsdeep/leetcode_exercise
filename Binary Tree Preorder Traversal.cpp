#include <iostream>
#include <queue>
#include <stack>
using namespace std;


 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> r;
        stack<TreeNode*> nodes;
        if(root==NULL)
        	return r;
        nodes.push(root);
        TreeNode* temp;
        while(!nodes.empty()){
        	temp = nodes.top();
        	r.push_back(temp->val);
        	nodes.pop();
        	if(temp->right)
        		nodes.push(temp->right);
        	if(temp->left)
        		nodes.push(temp->left);
        }
        return r;
    }
};


/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> r;
		help(root, r);

    }
    void help(TreeNode* root, vector<int>& r){
    	if(root==NULL)
    		return;
    	r.push_back(root->val);
    	help(root->left, r);
    	help(root->right, r);
    }
};
*/

int main(){
	cout << "hello";
}