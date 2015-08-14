#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
    	if(head==NULL || head->next==NULL)
    		return head;
    	ListNode* prev,*temp,*curr,*next;
    	curr = head->next->next;
    	temp = head;
    	head = head->next;
    	head->next = temp;
    	prev = head->next;



    	while(curr!=NULL && curr->next!=NULL){
    		next = curr->next->next;
    		temp = curr->next;
    		temp->next = curr;
    		prev->next = temp;
    		prev = curr;
    		curr = next;
    	}
    	prev->next = curr;
    	return head;
    }
};


int main(){
	Solution s = Solution();
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	head = s.swapPairs(head);
	while(head!=NULL){
		cout << head->val <<" ";
		head=head->next;
	}
}

