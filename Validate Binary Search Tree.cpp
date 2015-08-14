#include <iostream>
#include <stack>
#include <vector>
#include <limits>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        IsValidBST(root, numeric_limits<int>::min(),numeric_limits<int>::max());
    }

    bool help(TreeNode* node, int min, int max){
    	if(node==NULL)
    		return true;
    	if(node->val>min && node->val <max && help(node->left,node->val,max) && help(node->right,min,node->val))
    		return true;
    	return false;
    }

    bool IsValidBST(TreeNode* node, int MIN, int MAX)   
       {  
            if(node == NULL)  
                  return true;  
            if(node->val > MIN   
                      && node->val < MAX  
                      && IsValidBST(node->left,MIN,node->val)  
                      && IsValidBST(node->right,node->val,MAX))  
                 return true;  
            else   
                 return false;  
       }  
};

int main(){
	cout << "hello\n";
}
