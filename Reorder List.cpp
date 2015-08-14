#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

void print_list(ListNode* head){
	while(head!=NULL){
		cout << head->val;
		head = head->next;
	}
	cout << endl;

}


class Solution {
public:
    void reorderList(ListNode *head) {
    	if(head==NULL)
    		return;
    	ListNode* n1=head, * n2 = head;
    	ListNode* head2;
        while(true){
            if(n2->next==NULL){head2 = n1->next;n1->next=NULL;break;} else n2 = n2->next;
            if(n2->next==NULL){head2 = n1->next;n1->next=NULL;break;}  else n2 = n2->next;
            n1 = n1->next;
        }
        //print_list(head2);
        head2 = reverseList(head2);
        //print_list(head2);
        //print_list(head);
        mergeList(head, head2);
    }

    ListNode* mergeList(ListNode* n1, ListNode* n2){
    	ListNode* temp1;
    	ListNode* temp2;
    	while(n2!=NULL){
    		temp1 = n1->next;
    		temp2 = n2->next;
    		n1->next = n2;
    		n2->next = temp1;
    		n1 = temp1;
    		n2 = temp2;
    	}
    	return n1;
    }

    ListNode* reverseList(ListNode * head){
    	if(head==NULL)
    		return NULL;
    	ListNode* n1=head;
    	ListNode* n2=head->next;
    	head->next = NULL;
    	if(n2==NULL)
    		return n1;
    	while(n2!=NULL){
    		ListNode* temp = n2->next;
    		n2->next = n1;
    		n1 = n2;
    		n2 = temp;
    	}
    	return n1;
    }
};


int main(){
	//cout << "hello";
	ListNode* l = new ListNode(1);
	l->next = new ListNode(2);
	//l->next->next = new ListNode(3);
	//l->next->next->next = new ListNode(4);

	Solution s = Solution();
	s.reorderList(l);
	print_list(l);
}