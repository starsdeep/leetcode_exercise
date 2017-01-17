#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void print_vector(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}




class Solution {
public:

	// 不是很好，思路对了，就是把路径中经过的点放到stack中，但是不应该是，每次都pop出来。避免这种情况，
	//用一个node表示当前stack将要push的下一个点，如果node满足一定的条件，则不再push,而是pop。
    vector<int> inorderTraversal1(TreeNode *root) {
        vector<int> result;
        set<TreeNode*> poped;
        set<TreeNode*> inStack;
        if(root==NULL)
        	return result;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        while(!s.empty()){
        	node = s.top(); s.pop();
        	if(node->right!=NULL && inStack.find(node->right)==inStack.end()){
        		s.push(node->right);
        		inStack.insert(node->right);
        	}
        	if(node->left!=NULL && poped.find(node->left)==poped.end()){
        		s.push(node);
        		s.push(node->left);
        		inStack.insert(node->left);
        	}
        	else{
        		result.push_back(node->val);
        		poped.insert(node);
        	}
        }
        return result;
    }

    vector<int> inorderTraversal2(TreeNode *root) {
    	stack<TreeNode*> s;
    	vector<int> r;
    	while(root!=NULL || !s.empty()){
    		if(root!=NULL){
    			s.push(root);
    			root = root->left;
    		}
    		else{
    			root = s.top(); s.pop();
    			r.push_back(root->val);
    			root = root->right;
    			//s.push(root->right);
    		}
    	}
    	return r;
	}

};


int main(){
	cout << "hello" << endl;
	TreeNode* head = new TreeNode(1);
	head->right = new TreeNode(2);
	head->right->left = new TreeNode(3);
	Solution s = Solution();
	vector<int> r = s.inorderTraversal2(head);
	print_vector(r);

}
