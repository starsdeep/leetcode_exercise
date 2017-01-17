#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        int count = 0;
        ListNode* curr = head;
        while(curr!=NULL){ count++; curr=curr->next;}
        return help(head,0,count-1);
    }

    TreeNode* help(ListNode* & curr, int l, int r){
    	if(l>r) return NULL;
    	int m = (l+r)/2;
    	TreeNode* left = help(curr,l,m-1);
    	TreeNode* root = new TreeNode(curr->val);
    	root->left = left;
    	curr = curr->next;
    	root->right = help(curr,m+1,r);
    	return root;
    }
};

int main(){

}