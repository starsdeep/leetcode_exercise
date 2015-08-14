#include<iostream>

using namespace std;

struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		 int sizeA = ListSize(headA);
		 int sizeB = ListSize(headB);

		 if(headA == NULL || headB == NULL)
		 	return NULL; 

		 int diff = sizeA - sizeB;
		 ListNode * large = headA;
		 ListNode * small = headB;
		 if(sizeA < sizeB){
		 	diff = -diff;
		 	large = headB;
		 	small = headA;
		 }

		 cout << sizeA << " " << sizeB << " " << diff << endl;


		 while((diff--) > 0){
		 	large = large->next;
		 }

		 cout << large->val << " " << small->val << endl;

		 while(large->val != small->val){
		 	large = large -> next;
		 	small = small -> next;
		 	if(large == NULL)
		 		break;
		 }
		 return large;
    }

    int ListSize(ListNode *head){
    	int size = 0;
    	while(head){
    		size++;
    		head = head -> next;
    	}
    	return size;
    }

};

int main(){
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(3);
	list1->next->next = new ListNode(5);
	ListNode* list2 = new ListNode(2);

	Solution s;
	s.getIntersectionNode(list1,list2);

}


