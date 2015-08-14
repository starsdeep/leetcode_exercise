#include<iostream>
#include<queue>

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode* > q;
        if(root == NULL)
        	return;
        q.push(root);
        while(!q.empty()){
        	q = process_queue(q);
        }
        return;
    }

     queue<TreeLinkNode*> process_queue(queue<TreeLinkNode* >& q){
     	if(q.empty())
     		return q;
     	queue<TreeLinkNode*> next;
     	TreeLinkNode* pre_node = q.front(); q.pop();
     	while(!q.empty()){
     		TreeLinkNode* curr_node = q.front(); q.pop();
     		pre_node->next = curr_node;
     		push_child(next, pre_node);
     		pre_node = curr_node;
     	}
     	pre_node->next = NULL;
     	push_child(next, pre_node);
     	return next;
     }

     void push_child(queue<TreeLinkNode* >& q, TreeLinkNode* node){
     	if(node->left)
     		q.push(node->left);
     	if(node->right)
            q.push(node->right);
     }
};

int main(){
	Solution s = Solution();

	
}