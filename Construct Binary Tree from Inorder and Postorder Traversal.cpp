#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if(inorder.size()==0) return NULL;
    	TreeNode* root = new TreeNode(inorder[0]);
    	int pos = find(postorder.begin(), postorder.end(), inorder[0]) - postorder.begin();
    	
    	vector<int> postorder_left(postorder.begin(), postorder.begin()+pos);
    	vector<int> postorder_right(postorder.begin()+pos+1, postorder.end());
    	vector<int> inorder_left(inorder.begin()+1, inorder.begin()+1+pos);
    	vector<int> inorder_right(inorder.begin()+1+pos, inorder.end());
    	
    	root->left = buildTree(inorder_left, postorder_left);  
    	root->right = buildTree(inorder_right, inorder_right);

    	return root;
    }
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder,0,inorder.size(),postorder,0,postorder.size());
    }


    TreeNode* help(vector<int>& inorder,int i_begin, int i_end, vector<int>& postorder, int p_begin, int p_end){
    	if(i_begin==i_end) return NULL;
    	TreeNode* root = new TreeNode(inorder[i_begin]);

        int len = find(postorder.begin()+p_begin, postorder.begin()+p_end, inorder[i_begin]) - (postorder.begin() + p_begin);
    	
    	cout << "len: " << len << endl;

    	int p_begin_left = p_begin;
    	int p_end_left = p_begin + len;
    	int p_begin_right = p_begin + len + 1;
    	int p_end_right = p_end;

    	
    	int i_begin_right = i_begin + 1 ;
    	int i_end_right = i_begin_right + (p_end_right - p_begin_right);
        int i_begin_left = i_end_right;
        int i_end_left = i_begin_left + len;
        
        
    	root->left = help(inorder,i_begin_left,i_end_left, postorder, p_begin_left, p_end_left);
    	root->right = help(inorder,i_begin_right,i_end_right, postorder, p_begin_right, p_end_right);

    	return root;

    }
    
};

    

/*

int main(){
	Solution s;
	vector<int> in = {2,3,1};
	vector<int> po = {3,2,1};

	s.buildTree(in,po);

}
 
 */
