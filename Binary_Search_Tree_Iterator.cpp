#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
	stack<TreeNode* > s;
    BSTIterator(TreeNode *root) {
    	push_left(root);
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* curr = s.top()
        s.pop();
        push_left(curr);
        return curr->val;
    }

    void push_left(TreeNode* root){
    	while(root!=NULL){
    		s.push(root);
    		root = root->left;
    	}
    }


};