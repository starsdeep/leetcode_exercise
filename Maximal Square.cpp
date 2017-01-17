class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if(matrix.size()==0 || matrix[0].size()==0) return 0;
    	int global_max=0;
    	int res[matrix.size()+1][matrix[0].size()+1];
    	
    	for(int i=0;i<matrix.size()+1;i++){
    		for(int j=0;j<matrix[0].size()+1;j++){
    			if(i==0 || j==0){
    				res[i][j] = 0;
    				continue;
    			}
    			if(matrix[i-1][j-1] == '0'){
    				res[i][j] = 0;
    			}
    			else{
    				res[i][j] = min(min(res[i-1][j],res[i-1][j-1]), res[i][j-1]) + 1;	
    			}
    			global_max = max(global_max, res[i][j]);
    		}
    	}
    	return global_max * global_max;
    }
};
