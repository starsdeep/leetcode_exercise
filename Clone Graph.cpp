#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  		UndirectedGraphNode* r=NULL, *temp_node=NULL, *new_node=NULL;
  		map<int, UndirectedGraphNode*> vistited;
  		queue<UndirectedGraphNode *> q_new;
  		queue<UndirectedGraphNode *> q;
  		if(node!=NULL){
  			r = new UndirectedGraphNode(node->label);
  			//process_node(r, node);
  			q_new.push(r);
  			q.push(node);
  			vistited[r->label]=r;
  		}
  		while(!q.empty()){
  			node = q.front(), q.pop();
  			new_node = q_new.front(), q_new.pop();
  			//process_node(temp_node_new, temp_node, vistited);
  			
  			for(int i=0;i<node->neighbors.size();i++){
    			if(vistited.find(node->neighbors[i]->label)==vistited.end()){
    				temp_node = new UndirectedGraphNode(node->neighbors[i]->label);
    				new_node->neighbors.push_back(temp_node);
    				vistited[temp_node->label] = temp_node;
    				q.push(node->neighbors[i]);
    				q_new.push(new_node->neighbors[i]);
    			}
    			else{
    				new_node->neighbors.push_back(vistited[node->neighbors[i]->label]);
    			}
  			}
  		}
  		return r;
    }
};

int main(){
	cout << "hello";
	Solution s = Solution();
	s.cloneGraph(NULL);
}