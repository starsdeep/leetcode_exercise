#include <unordered_set>
#include <string>
#include <queue>
#include <set>
#include <iostream>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        string node, temp;
        queue<string> q;
        map<string,int> vistited;
        q.push(start);
        vistited[start] = 1;
        while(!q.empty()){
        	node = q.front(); q.pop();
        	if(node==end)
        		return vistited[node];
        	for(int i=0;i<node.size();i++){
    			for(char c='a';c<='z';c++){
    				if(node[i]!=c){
    					temp = node;
    					temp[i] = char(c);
    					if(dict.find(temp)!=dict.end()){
    						if(vistited.find(temp)==vistited.end()){
    							q.push(temp);
    							vistited[temp] = vistited[node] + 1;
    						}
    					}
    				}
    			}
    		}
        }
        return 0;
    }
};


class Solution1 {
public:
	struct UndirectedGraphNode {
		string label;
		int dist;
		bool vistited=false;
		vector<UndirectedGraphNode *> neighbors;
		UndirectedGraphNode(string x, int d) : label(x), dist(d) {};
	};

    int ladderLength(string start, string end, unordered_set<string> &dict) {
    	dict.insert(start), dict.insert(end);
        UndirectedGraphNode* g = construct_graph(start, dict), *node=NULL;
        if(dict.size()<=1)
        	return 0;
        //dfs
        queue<UndirectedGraphNode*> q;
       	g->dist = 1, g->vistited = true;
        //set<string> vistited;
        //vistited.insert(g->label);
        q.push(g);
        while(!q.empty()){
        	node = q.front();q.pop();
        	if(node->label==end)
        		return node->dist;
        	for(int i=0;i<node->neighbors.size();i++){
        		if(node->neighbors[i]->vistited==false){
        			node->neighbors[i]->vistited = true;
        			node->neighbors[i]->dist = node->dist + 1;
        			q.push(node->neighbors[i]);
        		}
        	}
        }
        return 0;
    }

    UndirectedGraphNode* construct_graph(string& start, unordered_set<string>& dict){
    	UndirectedGraphNode* g = new UndirectedGraphNode(start,0), *temp=NULL;
    	vector<UndirectedGraphNode* > v;
    	v.push_back(g);
    	for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++){
    		if(*it!=start){
    			temp = new UndirectedGraphNode(*it,0);
    			for(int i=0;i<v.size();i++){
    				if(match(v[i]->label,*it)){
    					v[i]->neighbors.push_back(temp);
    					temp->neighbors.push_back(v[i]);
    				}
    			}
    			v.push_back(temp);
    		}
    	}
    	return g;
    }


    bool match(string s1, string s2){
    	int unmatch = 0;
    	for(int i=0;i<s1.size();i++){
    		if(s1[i]!=s2[i]){
    			if(unmatch==0)
    				unmatch++;
    			else
    				return false;
    		}
    	}
  		return true;
    }
};

int main(){
	string start = "hit";
	string end = "cog";
	unordered_set<string> s;
	s.insert("hot");
	s.insert("dot");
	s.insert("dog");
	s.insert("lot");
	s.insert("log");

	Solution d = Solution();
	char c = 'g';
	//cout << d.match(start,"hot")<<endl;
	cout << char((c+1)) << endl;
	cout << d.ladderLength(start,end,s);

}


