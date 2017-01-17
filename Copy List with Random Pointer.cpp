#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct RandomListNode {
 	int label;
 	RandomListNode *next, *random;
 	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head==NULL) return NULL;
    	map<RandomListNode*, int> m;
    	vector<RandomListNode*> v;
    	RandomListNode* new_list = new RandomListNode(head->label);
    	
    	RandomListNode* prev = new_list;
    	m[head] = 0;
    	RandomListNode* curr = head->next;
    	int i=1;

    	while(curr){
    		v.push_back(prev);
    		prev->next = new RandomListNode(curr->label);
    		prev = prev->next;
    		m[curr] = i;
    		curr = curr->next;
    		i++;
    	}
    	v.push_back(prev);
    	prev->next = NULL;

    	curr = head;
    	RandomListNode* new_curr = new_list;
    	while(curr){
    		if(curr->random==NULL)
    			new_curr->random = NULL;
    		else
    			new_curr->random = v[m[curr->random]];
    		curr = curr->next;
    		new_curr = new_curr->next;
    	}

    	return new_list;
    }
};

int main(){

}