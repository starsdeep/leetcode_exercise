// problem description http://hihocoder.com/contest/hiho18/problem/1

#include<iostream>
#include<vector>


using namespace std;

struct Node{
    int left,right,min;
    Node * leftchild;
    Node * rightchild;
};



int main(){
    const int  MIN = numeric_limits<int>::min();
    int N;
    cin >> N;
    vector<int> items(N);
    for(int i = 0; i < N; i++){
        cin >> items[i];
    }
    
    int Q;
    cin >> Q;
    
    /*
    Node* root = new Node;
    root -> left = 1;
    root -> right = N;
    root -> min = *min_element(items.begin(),items.end());
    */
    int v1,v2,v3;
    while(Q--){
        cin >> v1 >> v2 >> v3;
        if(v1){
            items[v2 - 1] = v3; 
        }
        else{
            cout << *min_element(&items[v2-1], &items[v3-1]) << endl;   
        }
    }


}
