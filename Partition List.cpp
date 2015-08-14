#include <iostream> 
  
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};

void print_array(ListNode* head){
	while(head!=NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* head_small=NULL, *tail_small=NULL;
        ListNode* head_big=NULL, *tail_big=NULL;
        while(head!=NULL){
        	if(head->val<x){
        		if(head_small==NULL){
        			head_small=head;
        			tail_small = head_small;
        		}
        		else{
        			tail_small->next = head;
        			tail_small = tail_small->next;
        		}
        	}
        	else{
        		if(head_big==NULL){
        			head_big=head;
        			tail_big = head_big;
        		}
        		else{
        			tail_big->next = head;
        			tail_big = tail_big->next;
        		}
        	}
        	head = head->next;
        }
        if(head_small!=NULL)
        	tail_small->next = head_big;
        else
        	return head_big;
        if(tail_big!=NULL)
        	tail_big->next = NULL;
       
        return head_small;
    }
};

int main(){
	Solution s = Solution();
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head = s.partition(head,4);
	print_array(head);
}

