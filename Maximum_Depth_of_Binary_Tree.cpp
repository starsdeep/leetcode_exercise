#include <iostream>

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
    int max(int a, int b){
        return a>b?a:b;
    }
};

int main(){

	cout << "hello";
}

