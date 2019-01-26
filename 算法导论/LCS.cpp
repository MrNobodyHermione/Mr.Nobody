#include<bits/stdc++.h>
using namespace std;
string ss1,ss2;
char s1[110],s2[110];
int f[110][110]={0};
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
    for(int i=1;i<=slen1;i++){
        for(int j=1;j<=slen2;j++){
            if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[j-1][i]);
        }
    }

    cout<<f[slen1][slen2]<<endl;
    return 0;
}
