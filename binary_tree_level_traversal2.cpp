#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {

      vector<vector<int> >result;
   		vector<TreeNode*> prevLevel;
   		
      if(root == NULL)
        return result;


      prevLevel.push_back(root);
   		while(prevLevel.size()){
   			prevLevel = processLevel(prevLevel, result);
   		}

      std::reverse(result.begin(),result.end());
   		return result;
    };

    vector<TreeNode*> processLevel(vector<TreeNode*>& prevLevel, vector<vector<int> >& levelOrder){
    	vector<int> tmp;
    	vector<TreeNode*> nextLevel;
    	for(vector<TreeNode*>::iterator it = prevLevel.begin(); it!=prevLevel.end(); ++it){
    		tmp.push_back((*it)->val);
    		if((*it)->left)
                nextLevel.push_back( (*it)->left) ;
    		if((*it)->right)
                nextLevel.push_back( (*it)->right) ;
    	}
        levelOrder.push_back(tmp);
    	return nextLevel;
    }
};


int main(){

    TreeNode* root = new TreeNode(0) ;
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
   
    Solution s;
    vector<vector<int> >result = s.levelOrder(root);
    cout << "program begin\n";
    cout << result.size() << endl;


    for(vector<vector<int> >::iterator it = result.begin(); it!=result.end(); ++it){
        for(vector<int>:: iterator j = (*it).begin(); j != (*it).end(); ++j ){
            cout << *j << ' ';
        }
        cout << endl;
    }
}
