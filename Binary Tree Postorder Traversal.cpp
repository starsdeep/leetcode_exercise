#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <vector.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root){
    	set<TreeNode*> visited;
    	stack<TreeNode*> s;
    	vector<int> result;
    	if(root==NULL) return result;
    	
    	TreeNode* temp;
    	while(root || !s.empty()){
    		if(root){
    			s.push(root);
    			root = root->left;
    		}
    		else{
    			if(!s.empty()){
    				temp = s.top();s.pop();

    				if(temp->right && visited.find(temp->right)==visited.end()){
    					s.push(temp);
    					visited.insert(temp->right);
    					root = temp->right;
    				}    					
    				else{
    					result.push_back(temp->val);
    				}
    			}
    		}
    	}
    	return result;
    }
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	Vector<int> v = Vector<int>(s.postorderTraversal(root));
	cout << v.toString();
}