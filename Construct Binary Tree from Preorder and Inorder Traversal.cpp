#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
     	TreeNode* head=NULL;
     	if(preorder.size()==0 || inorder.size()==0)
     		return head;
     	map<int,int> m;
     	for(int i=0;i<inorder.size();i++)
     		m[inorder[i]] = i;
     	return help(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
     	

    }

    TreeNode* help(vector<int> &preorder, int preL, int preR, vector<int>& inorder, int inL, int inR, map<int,int>& m){
    	if(preL>preR || inL>inR)
    		return NULL;
    	TreeNode* node = new TreeNode(preorder[preL]);
    	int idx = m[preorder[preL]];
    	cout << node->val << endl; 
    	node->left = help(preorder, preL+1, preL+idx-inL, inorder, inL, idx-1,m);
    	node->right = help(preorder, preL+idx-inL+1, preR, inorder, idx+1, inR,m);
    	return node;
    }
};

int main(){
	cout << "hello"<<endl;
	Solution s = Solution();
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v2.push_back(1);
	s.buildTree(v1,v2);
}