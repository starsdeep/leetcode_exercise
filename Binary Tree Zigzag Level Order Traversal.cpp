#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void print_2d_vector(vector<vector<int> >x){
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i].size();j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }
}

void print_vector(vector<int> x){
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> item;
        TreeNode* node;
        if(root==NULL)
        	return result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, curr = 1, next=0;
        while(!q.empty()){
        	curr--;
        	node = q.front(); q.pop();
        	item.push_back(node->val);
        	if(node->left) {q.push(node->left); next++;}
        	if(node->right) {q.push(node->right); next++;}
        	if(curr==0){
        		curr = next;
        		next = 0;
        		if(level%2==0)
        			reverse(item.begin(),item.end());
        		result.push_back(item);
        		item.clear();
        		level++;
        	}
        }
        return result;
    }
};

int main(){
	cout << "hello"<<endl;
	TreeNode* head = new TreeNode(3);
	head->left = new TreeNode(9);
	head->right = new TreeNode(20);
	Solution s = Solution();
	vector<vector<int> > result = s.zigzagLevelOrder(head);
	print_2d_vector(result);
}


