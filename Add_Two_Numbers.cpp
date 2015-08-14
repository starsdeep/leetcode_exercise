#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  		int i = 0;
  		int step = 0;
  		int value;
  		
  		if(l1 == NULL || l2 == NULL)
  			return NULL;

  		value = (l1->val + l2->val + step) % 10;
  		step = (l1->val + l2->val + step) / 10;
  		ListNode * result = new ListNode(value);

  		ListNode * ptr1 = l1->next;
  		ListNode * prt2 = l2->next;
  		ListNode * cur = result;
  		while(ptr1!=NULL && prt2!=NULL){
  			value = (ptr1->val + prt2->val + step) % 10;
  			step = (ptr1->val + prt2->val + step) / 10;
  			ListNode * tmp = new ListNode(value);
  			cur->next = tmp;
  			cur = cur->next;
  			ptr1 = ptr1->next;
  			prt2 = prt2->next; 			
  		}
  		if(ptr1 || prt2){
  			ListNode * ptr = ptr1 ? ptr1:prt2;
  			while(ptr){
  				ListNode * tmp = new ListNode((ptr->val + step)%10);
  				step = (ptr->val + step) / 10;
  				cur->next = tmp;
  				cur = cur ->next;
  				ptr = ptr->next;
  			}
  		}
  		if(step){
  			cur->next = new ListNode(step);
  		}    
  		return result;
    }
};

int main(){
	Solution s;
	cout << "test";
}