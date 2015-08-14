#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
    	if(head==NULL)
        	return NULL;
        ListNode* sorted_tail=head, *node, *prev, *curr;
        while(sorted_tail->next!=NULL){
        	node = sorted_tail->next;
        	if(node->val >= sorted_tail->val){
        		sorted_tail=node;
        	}
        	else{
        		sorted_tail->next = node->next;
        		curr=head, prev = NULL;
        		while(node->val >= curr->val){
        			prev = curr;
        			curr = curr->next;
        		}
        		if(prev){
        			prev->next = node;
        			node->next = curr;
        		}
        		else{
        			node->next = curr;
        			head = node;
        		}
        	}
        }
        return head;
    }
};


//naive version
class Solution1 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL)
        	return NULL;
        ListNode* r = new ListNode(head->val);
        head = head->next;
        while(head!=NULL){
        	r = insert(r,head->val);
        }
        return r;
    }
    ListNode* insert(ListNode* head, int value){
    	ListNode* prev = NULL;
    	while(head!=NULL && value > head->val){
    		prev = head;
    		head = head->next;
    	}
    	ListNode* new_node = new ListNode(value);
    	if(prev){
    		prev->next = new_node;
    		new_node->next = head;
    		return head;
    	}
    	else{
    		new_node->next = head;
    		return new_node;
    	}
    }
};

int main(){
	cout << "hello";
}