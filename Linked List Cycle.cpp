
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
    	ListNode* n1=head, * n2 = head;
    	while(true){
    		if(n2==NULL) return false; else n2 = n2->next;
    		if(n2==NULL) return false; else n2 = n2->next;
    		n1 = n1->next;
    		if(n1 == n2)
    			return true;
    	}
    }
};