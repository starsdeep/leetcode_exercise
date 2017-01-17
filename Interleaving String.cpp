//#include<stdio.h>
//#include<string.h>

#include<iostream>

using namespace std;

// bool isInterleave(char* s1, char* s2, char* s3) {
//     if(*s1=='\0')
//         return strcmp(s2,s3)==0;
//     if(*s2=='\0')
//         return strcmp(s1,s3)==0;
    
//     if(*s3==*s1 && *s3==*s2){
//         return isInterleave(s1++, s2, s3+1) || isInterleave(s1, s2++,s3+1);
//     }
//     if(*s3==*s1)
//         return isInterleave(s1++,s2,s3++);
//     if(*s3==*s2)
//         return isInterleave(s1,s2++,s3++);
//     return false;
// }


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        bool table[s1.size()+1][s2.size()+1];
        for(int i=0;i<s1.size()+1;i++){
            for(int j=0;j<s2.size()+1;j++){
                if(i==0 && j==0) table[i][j] = true;
                else if(i==0) table[i][j] = table[i][j-1] && s2[j-1]==s3[i+j-1];
                else if(j==0) table[i][j] = table[i-1][j] && s1[i-1]==s3[i+j-1];
                else table[i][j] = table[i-1][j] && s1[i-1]==s3[i-1+j] || table[i][j-1] && s2[j-1]==s3[i+j-1];
            }
        }
        return table[s1.size()][s2.size()];
    }
};

int main(){
    // char s1[6] = {'a','a','b','c','c','\0'};
    // char s2[6] = {'d','b','b','c','a','\0'};
    // char s3[11] = {'a','a','d','b','b','c','b','c','a','c','\0'};
    
    // if(isInterleave(s1,s2,s3))
    //     printf("yes");
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    Solution s = Solution();
    cout << s.isInterleave(s1,s2,s3);



}