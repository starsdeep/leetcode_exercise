#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL)
        	return head;
        return mergeSort(head);
    }

	ListNode* mergeSort(ListNode* head){
		if(head->next==NULL)
			return head;
		ListNode* ptr1=head, *ptr2=head, *temp;
		while(true){
			ptr2 = ptr2->next;
			if(ptr2==NULL)
				break;
			ptr2 = ptr2->next;
			if(ptr2==NULL)
				break;
			ptr1 = ptr1->next;
		}
		temp = ptr1->next;
		ptr1->next = NULL;
		return mergeTwoLists(mergeSort(head), mergeSort(temp));

	}

    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
   		if(l1==NULL)
   			return l2;
   		if(l2==NULL)
   			return l1;
   		ListNode* ptr1=l1, *ptr2=l2, *head, *prev, *temp;
   		if(l1->val > l2->val){
   			ptr1 = l2;
   			ptr2 = l1;
   		}
   		prev = head = ptr1;
   		ptr1 = ptr1->next;
   		while(ptr1!=NULL && ptr2!=NULL){
   			if(ptr1->val <= ptr2->val){
   				prev->next = ptr1;
   				prev = ptr1; 
   				ptr1 = ptr1->next;
   			}
   			else{
   				prev->next = ptr2;
   				prev = ptr2;
   				ptr2 = ptr2->next;
   			}
   		}
   		if(ptr1==NULL)
   			prev->next = ptr2;	
   		if(ptr2==NULL)
   			prev->next = ptr1;
   		return head;
    }
};

int main(){
	cout << "hello";
}