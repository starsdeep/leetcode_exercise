#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {

    		if(k==0 || head==NULL)
    			return head;

			ListNode * tail = head;
			ListNode * curr = head;
			ListNode * temp;
			int len = 1;

			while(tail->next != NULL){
				tail = tail->next;
				len++;
			}

			if(len==k)
				return head;
			//cout << "len:" << len << endl;
			int idx = len - 1 - k % len;;
			//cout << len << " " << idx;
			int i=0;
			while(i<idx){
				curr = curr->next;
				i++;
			}
			temp = head;
			head = curr->next;
			curr->next=NULL;
			tail->next = head;

			return head;
    }
};

int main(){
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);

	Solution s = Solution();
	s.rotateRight(head,3);


}