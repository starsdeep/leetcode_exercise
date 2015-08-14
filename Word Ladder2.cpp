#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

void print_2d_vector(vector<vector<string> >x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
}

void print_vector(vector<string> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void print_set(set<string> x){
    for(set<string>::iterator it = x.begin();it!=x.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}





	class Solution {
	public:
	    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	        vector<vector<string>> result, temp_result;
	        queue<string> q;
	        set<string> vistited;
	        set<string> local_vistited;
	        map<string,set<string> > parent;
	        set<string> p;
	        int lastNum=1, currNum=0;
	        string node,temp;
	        q.push(start);
	        vistited.insert(start);
	   		parent[start] = p;
	   		bool find = false;
	        while(!q.empty()){
	        	node = q.front();q.pop();
	        	lastNum--;     	
	        	for(int i=0;i<node.size();i++){	
	        		for(char c='a';c<='z';c++){
	        			if(node[i]==char(c))
	        				continue;
	        			temp = node;temp[i]=c;
	        			if(temp==end){
	        				if(parent.find(temp)!=parent.end())
	        					parent[temp].insert(node);
	        				else{
	        					p.clear();
	        					p.insert(node);
	        					parent[temp] = p;
	        				}	
	        				find = true;        			
	        			}
	        			if(dict.find(temp)!=dict.end()){
	        			 	if(vistited.find(temp)==vistited.end()){
	        					//cout << "1:  " << temp << endl;
	        					q.push(temp);
	        					vistited.insert(temp);
	        					local_vistited.insert(temp);
	        					currNum++;
	        				}
	        				if(vistited.find(temp)==vistited.end() || local_vistited.find(temp)!=local_vistited.end()){
	        					if(parent.find(temp)!=parent.end())
	        						parent[temp].insert(node);
	        					else{
	        						p.clear();
	        						p.insert(node);
	        						parent[temp] = p;
	        					}	
	        				}
	        			}
	        		}
	        	}
	        	if(lastNum==0){
	        		if(find){
	        			temp_result = getPath(end,parent);
						for(int i=0;i<temp_result.size();i++)
							result.push_back(temp_result[i]);
	        			break;
	        		}
	        		local_vistited.clear();
	        		lastNum = currNum;
	        		currNum = 0;
	        	}
	        }
	        return result;

	    }

	    vector<vector<string> > getPath(string start, map<string,set<string> >& parent){
	    	vector<vector<string> > path, path_new;
	    	vector<string> temp2;
	    	set<string> node_parents;
	    	string node;
	    	temp2.push_back(start);
	    	path_new.push_back(temp2);
	    	//vector<string> temp1=parent[start];
	    	queue<string> parents;
	    	parents.push(start);
	    	//for(int i=0;i<temp1.size();i++)
	    	//	parents.push(temp1[i]);
	    	while(!parents.empty()){
	    		node = parents.front();parents.pop();
	    		node_parents = parent[node];
	    		//cout << "node: " << node << endl;
	    		//cout << "node parents size: " << node_parents.size() << ", parents: ";
	    		//print_set(node_parents);
	    		if(node_parents.size()==0)
	    			continue;
	    		path = path_new;
	    		path_new.clear();
	    		for(int i=0;i<path.size();i++){
	    			temp2 = path[i];
	    			if(temp2[temp2.size()-1]==node){
	    				for(set<string>::iterator it = node_parents.begin();it!=node_parents.end();it++){
	    					temp2 = path[i];
	    					temp2.push_back(*it);
	    					path_new.push_back(temp2);
	    					parents.push(*it);
	    				}
	    			}
	    			else
	    				path_new.push_back(temp2);
	    		}
	    	}

	    	for(int i=0;i<path_new.size();i++){
	    		reverse(path_new[i].begin(),path_new[i].end());
	    	}
	    	//cout <<"size : " << path_new.size() << endl;
	    	return path_new;
	    }
	};

int main(){
	string start = "red";
	string end = "tax";
	unordered_set<string> s; 
	s.insert("ted");
	s.insert("tex");
	s.insert("red");
	s.insert("tax");
	s.insert("tad");
	s.insert("den");
	s.insert("rex");
	s.insert("pee");

	Solution d = Solution();
	//char c = 'g';
	//cout << d.match(start,"hot")<<endl;
	//cout << char((c+1)) << endl;
	vector<vector<string> > r;
	r = d.findLadders(start,end,s);
	print_2d_vector(r);

}
