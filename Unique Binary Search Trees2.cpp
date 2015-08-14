#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
    	vector<vector<TreeNode *> > tree_template;
    	vector<TreeNode *> temp_vec, temp_vec_right, temp_vec_left;
    	tree_template.push_back(temp_vec);
    	TreeNode * temp_tree = new TreeNode(1);
    	temp_vec.push_back(temp_tree);
    	tree_template.push_back(temp_vec);
    	if(n==1)
    		return tree_template[1];
    	vector<int> v;
    	for(int len=2;len<=n;len++){
    		for(int root=1;root<=len;root++){			
    			//right
    			v.clear();
    			v = vector<int>(len-root);
    			iota(v.begin(), v.end(), root+1);
    			temp_vec_right = instantiate(len-root,v,tree_template);
    			//left
    			v.clear();
    			v = vector<int>(root);
    			iota(v.begin(),v.end(),root);
    			v[root-1] = len;
    			temp_vec_left = instantiate(root,v,tree_template);

    			if(temp_vec_left.size()==0){
    				for(int i=0;i<temp_vec_right.size();i++){
    					temp_tree = new TreeNode(root);
    					temp_tree->right = temp_vec_right[i]; 
    					tree_template[len].push_back(temp_tree);
    					continue;
    				}
    			}
    			if(temp_vec_right.size()==0){
    				for(int i=0;i<temp_vec_left.size();i++){
    					temp_tree = new TreeNode(root);
    					temp_tree->left = temp_vec_right[i]; 
    					tree_template[len].push_back(temp_tree);
    					continue;
    				}
    			}
    			for(int i=0;i<temp_vec_left.size();i++){
    				for(int j=0;j<temp_vec_right.size();j++){
    					temp_tree = new TreeNode(root);
    					temp_tree->left = temp_vec_left[i];
    					temp_tree->right = temp_vec_right[j];
    					tree_template[len].push_back(temp_tree);
    				}
    			}
    		}
    	}
    	return tree_template[n];
    }

    vector<TreeNode *> instantiate(int n, vector<int>& v, vector<vector<TreeNode *> >& tree_template){
    	vector<TreeNode *> result;
    	if(n==0)
    		return result;
    	for(int i=0;i<tree_template[n].size();i++)
    		result.push_back(instantiate_single(tree_template[n][i],v));
    	return result;
    }

    TreeNode* instantiate_single(TreeNode* head, vector<int>& v){
    	TreeNode * result = new TreeNode(v[head->val]);
    	if(head->left!=NULL) 
    		result->left = instantiate_single(head->left, v);
    	if(head->right!=NULL)
    		result->right = instantiate_single(head->right, v);
    	return result;
    }

};

int main(){
	Solution s = Solution();
	cout << "hello";
}


