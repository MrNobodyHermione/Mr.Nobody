/*
ID: hjl11841
TASK: runround
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int a[210];
int b[210];
int h[210];
int m;
int hermione(int x){
    int t=0;
    while(x>0){
        b[++t]=x%10;
        x/=10;
    }
    for(int i=1;i<=t;++i){
		a[i]=b[t-i+1];
	}
    return t; 
}
bool check(){
    int t=1;
    memset(h,0,sizeof h);
    for(int i=1;i<=m;++i){
        if(h[a[t]]||a[t]==0)return 0;
        h[a[t]]++;
        t=(t+a[t])%m;
        if(t==0)t=m; 
    }
    if(t!=1)return 0;
    return 1;
}
int main(){
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
    int n;
    cin>>n;
    while(233){
        n++;
        m=hermione(n);
        if(check()){
           cout<<n<<endl;
           return 0;
        }
    }
    return 0;
}
