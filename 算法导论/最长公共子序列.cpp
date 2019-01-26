#include<bits/stdc++.h>
using namespace std;
string ss1,ss2;
char s1[110],s2[110];
int ans=0;
int h[110][110];
int LCS(int len1,int len2){
    if(h[len1][len2]!=-1) return h[len1][len2];
    if(!len1||!len2) return 0;
    if(s1[len1]==s2[len2]){
        h[len1][len2]=1;
        h[len1][len2]+=LCS(len1-1,len2-1);
    }
    else h[len1][len2]=max(LCS(len1-1,len2),LCS(len1,len2-1));
    return h[len1][len2];
}
int main(){
    cin>>ss1>>ss2;

    for(int i=0;i<ss1.size();i++){
        s1[i+1]=ss1[i];
    }
    for(int i=0;i<ss2.size();i++){
        s2[i+1]=ss2[i];
    }
    int slen1=ss1.size();
    int slen2=ss2.size();
    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            h[i][j]=-1;
        }
    }

    cout<<LCS(slen1,slen2)<<endl;
    return 0;
}