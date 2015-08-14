#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
 		ListNode* prev;
 		ListNode* curr;
 		
 		int dvalue;

 		curr = head;
 		
 		if(NodeCode(curr)==0 || NodeCode(curr)==1)
 				return curr;

 		while(NodeCode(curr) == 2){
 			curr = deleteSegment(curr);
 		}

 		head = curr;
 		if(NodeCode(head)==0 || NodeCode(head)==1)
 				return head;	

 		prev = head;
 		curr = head->next;
 
 		while(NodeCode(curr)!=0 && NodeCode(curr)!=1){
 			if(NodeCode(curr)==2){
 				curr = deleteSegment(curr);
 				prev->next = curr;
 			}	
 			else{
 				prev = curr;
 				curr = curr->next;
 			}
 		}
 		return head;
    }

    int NodeCode(ListNode* curr){
    	if(curr == NULL)
    		return 0;
    	if(curr->next == NULL)
    		return 1;
    	if(curr->val == curr->next->val){
    		return 2;
    	}
    	return 3;
    }

    ListNode* deleteSegment(ListNode* curr){
    	int val = curr->val;
    	ListNode* tmp;
    	while(curr && curr->val == val){
 				tmp = curr;
 				curr = curr->next;
 				delete tmp;
 		}
 		return curr;
    }

};


int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(3);

	Solution s;
	ListNode* result = s.deleteDuplicates(head); 

	ListNode* curr = result;
	while(curr){
		cout << curr->val << " "; 
		curr = curr->next;
	}
}


