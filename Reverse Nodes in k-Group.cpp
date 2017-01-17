#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode* curr = head;
        while(curr){ len++;curr=curr->next;}
        
        int count = len / k;
        ListNode* first = head;
        ListNode* tail = NULL;
        int j=0;
        
        while(j<count){
        	ListNode* prev = first;
        	curr = prev->next;
       		ListNode* temp;
       		int i=0;
       		while(i<k-1){
       			temp = curr->next;
       			curr->next = prev;
       			prev = curr;
       			curr = temp;
       			i++;
       		}
       		if(j==0)
       			head = prev;
       		first->next = curr;
       		if(tail)
       			tail->next = prev;
       		tail = first;
       		first = curr;
       		j++;
       	}
       	return head;
    }
};

int main(){

}