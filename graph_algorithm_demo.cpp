#include <iostream>
#include <queue>
#include <stack>
#include <set>
using namespace std;


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void bfs(UndirectedGraphNode* g){
	if(g==NULL) return;
	queue<UndirectedGraphNode*> q;
	set<UndirectedGraphNode*> visited;
	UndirectedGraphNode* node;
	q.push(g);
	visited.insert(g);
	while(!q.empty()){
		node  = q.front(); q.pop();
		cout << node->label << " "; // do something
		for(int i=0;i<node->neighbors.size();i++){
			if(visited.find(node->neighbors[i])==visited.end()){
				q.push(node->neighbors[i]);
				visited.insert(node->neighbors[i]);
			}
		}
	}
}

void dfs_recursive(UndirectedGraphNode* g, set<UndirectedGraphNode*>& visited){
	if(g==NULL) return;
	cout << g->label << " "; // do something
	visited.insert(g);
	for(int i=0;i<g->neighbors.size();i++){
		if(visited.find(g->neighbors[i])==visited.end()){
			visited.insert(g->neighbors[i]);
			dfs_recursive(g->neighbors[i],visited);
		}
	}
}


void dfs_iterative(UndirectedGraphNode* g){
	if(g==NULL) return;
	stack<UndirectedGraphNode*> q;
	set<UndirectedGraphNode*> visited;
	UndirectedGraphNode* node;
	q.push(g);
	visited.insert(g);
	while(!q.empty()){
		node  = q.top(); q.pop();
		cout << node->label << " "; // do something
		for(int i=0;i<node->neighbors.size();i++){
			if(visited.find(node->neighbors[i])==visited.end()){
				q.push(node->neighbors[i]);
				visited.insert(node->neighbors[i]);
			}
		}
	}
}



int main(){
	UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
	UndirectedGraphNode* node3 = new UndirectedGraphNode(3);
	UndirectedGraphNode* node4 = new UndirectedGraphNode(4);

	node1->neighbors.push_back(node2), node1->neighbors.push_back(node3);
	node2->neighbors.push_back(node4);

	//bfs(node1);
	//dfs_iterative(node1);
	set<UndirectedGraphNode*> visited;
	dfs_recursive(node1,visited);
}