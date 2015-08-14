#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
    ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };
 


class Solution {
public:
	struct comparator{
   		bool operator()(ListNode* left, ListNode* right){
			return left->val > right->val;
		}
	};

    ListNode *mergeKLists(vector<ListNode *> &lists) {
   		 priority_queue<ListNode*,vector<ListNode*>, comparator> q;
   		 for(int i=0;i<lists.size();i++){
   		 	if(lists[i]==NULL)
   		 		continue;
   		 	q.push(lists[i]);
   		 }
   		 ListNode* root=NULL, *tail, *node;
   		 if(q.empty()) return root;
   		 node = q.top();
   		 q.pop();
   		 root = node;
   		 tail = node;
   		 if(node->next) q.push(node->next);
   		 while(!q.empty()){
   		 	node = q.top(); q.pop();
   		 	tail->next = node;
   		 	tail = tail->next;
   		 	if(node->next)
   		 		q.push(node->next);
   		 }
   		 return root;
    }
};

int main(){
	cout << "hello\n";
}


