
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        ListNode* n1=head, * n2 = head;
        bool meet = false;
        int loop_len = 0;
        while(true){
            if(n2==NULL) return NULL; else n2 = n2->next;
            if(n2==NULL) return NULL; else n2 = n2->next;
            n1 = n1->next;
            if(n1 == n2){
                if(!meet)
                    meet = true;
                else
                    break;
            }
            if(meet)
                loop_len++;
        }
        n1 = n2 = head;
        int i=0;
        while((i++)<loop_len)
            n2=n2->next;
        while(n1!=n2){
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};


