/*
ID: hjl11841
TASK: dualpal
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool ispal(int n,int k){
    short res[100]={0},p=0;
    while(n){
        res[p++]=n%k;
        n/=k;
    }
    int i=0,j=p-1;
    while(i<j)
        if(res[i++]!=res[j--])return 0;
    return 1;
}
int main(){
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,s;
    cin>>n>>s;

    int ans=0;
    for(int i=s+1;ans!=n;i++){
        int cnt=0;
        for(int j=2;j<=10&&cnt<2;j++){
            if(ispal(i,j)) cnt++;
        }
        if(cnt>=2){
            cout<<i<<endl;
            ans++;
        }
    }
    return 0;
}
