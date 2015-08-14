#include <iostream>
#include <vector>

using namespace std;

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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
     	vector<vector<int> > r;
     	vector<int> item;
     	if(root!=NULL)
     		help(root,r,item,sum);
     	return r; 
    }

    void help(TreeNode* root, vector<vector<int> >&result, vector<int> item, int sum){
    	item.push_back(root->val);
    	sum -= root->val;
    	if(root->left==NULL && root->right==NULL && sum==0){	
    		result.push_back(item);
    		return;
    	}
    	if(root->left)
    		help(root->left,result,item,sum);
   		if(root->right)
   			help(root->right,result,item,sum);
   	}
};

int main(){
	cout << "hello" << endl;
	Solution s = Solution();
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	vector<vector<int> > r = s.pathSum(root,3);
	print_2d_vector(r);
}



