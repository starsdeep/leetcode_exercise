#include<iostream>
#include<vector>


using namespace std;

int max(int n1, int n2){
    if(n1 > n2)
        return n1;
    else
        return n2;
}
int min(int n1, int n2){
    if(n1 < n2)
        return n1;
    else
        return n2;
}




int main(){
    int c = 0;
    cin >> c;
    int l = 0;
    int n = 0;
    while(c--){
        cin >> l;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
        }
    
    int max_value = 0;
    int min_value = 0;
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        max_value = max(max_value,max(*it,l - *it));
        min_value = max(min_value,min(*it,l - *it));
    }
    cout << min_value << " " << max_value << endl;
    }
}
