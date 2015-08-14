#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head){
	while(head!=NULL){
		cout << head->val << " ";
		head=head->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL || head->next==NULL || m==n)
        	return head;
        ListNode* left_end, *reverse_head, *prev, *curr, *temp;
        if(m==1) left_end = NULL; else left_end = head;
      	int i=1;
        while((i+1)<m && left_end!=NULL){
        	left_end = left_end->next;
        	i++;
        }
        i = m+1;
        if(left_end!=NULL){
        	curr = left_end->next->next;
        	reverse_head = prev = left_end->next;
        }
        else{
        	curr = head->next;
        	reverse_head = prev = head;
        }
        
        while(curr!=NULL && i<=n){
        	temp = curr->next;
        	curr->next = prev;
        	prev = curr;
        	curr = temp;
        	i++;
        }
        if(left_end){
        	left_end->next = prev;
        	reverse_head->next = temp;
        	return head;
        }
        else{
        	reverse_head->next = temp;
        	return prev;
        }
    }
};

int main(){
	cout << "hello" << endl;
	Solution s = Solution();
	ListNode* head = new ListNode(3);
	head->next = new ListNode(5);
	print_list(head);
	head = s.reverseBetween(head,1,2);
	print_list(head);

}