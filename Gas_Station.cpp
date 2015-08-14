#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
        vector<int> diff = minus(gas,cost);       
        int pos = maxSubArray(diff);
        
        cout << pos;
        int gas_volume = 0;
        for(int i=pos;i<gas.size();i++){
            gas_volume += gas[i];
            gas_volume -= cost[i];
            if(gas_volume < 0)
                return -1;
        }
        for(int i=0;i<pos;i++){
            gas_volume += gas[i];
            gas_volume -= cost[i];
            if(gas_volume < 0)
                return -1;
        }
        return pos;
    }

    int maxSubArray(vector<int>& v){
        int global_max = v[0];
        int local_max = v[0];
        int global_max_start = 0;
        int local_max_start = 0;
        
        for(int i=1;i<v.size();i++){
            if(v[i] > local_max + v[i]){
                local_max = v[i];
                local_max_start = i; 
            }
            else
                local_max += v[i];
            if(local_max > global_max){
                global_max = local_max;
                global_max_start = local_max_start;
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i] > local_max + v[i]){
                break;
            }
            else
                local_max += v[i];
            if(local_max > global_max){
                global_max = local_max;
                global_max_start = local_max_start;
            }
        }
        return global_max_start;
    }

    vector<int> minus(vector<int>& v1, vector<int>& v2){
        vector<int> v3;
        for(int i=0;i<v1.size();i++){
            v3.push_back(v1[i] - v2[i]);
        }
        return v3;
    }

    int max(int a, int b){
        return {a>b?a:b};
    }

};

int main(){
    vector<int> v1,v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(3);
    
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(2);
    
    Solution s;
    cout << s.canCompleteCircuit(v1,v2);

}
