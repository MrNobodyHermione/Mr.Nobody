/*
ID: hjl11841
TASK: combo
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5],b[5];
int ans=0;
int c[5];
int h[101][101][101];
void fj(int dep){
    if(dep>3){
        if(h[c[1]][c[2]][c[3]]==1) return;
        h[c[1]][c[2]][c[3]]=1;
        ans++;
        return;
    }
    for(int i=-2;i<=2;i++){
        int tmp=a[dep]-i;
        if(tmp<=0) tmp=n+tmp;
        if(tmp>n) tmp-=n;
        if(tmp>0&&tmp<=n){
            c[dep]=tmp;
            fj(dep+1);
        }
    }
}
void master(int dep){
    if(dep>3){
        if(h[c[1]][c[2]][c[3]]==1) return;
        h[c[1]][c[2]][c[3]]=1;
        ans++;
        return;
    }
    for(int i=-2;i<=2;i++){
        int tmp=b[dep]-i;
        if(tmp<=0) tmp=n+tmp;
        if(tmp>n) tmp-=n;
        if(tmp>0&&tmp<=n){
            c[dep]=tmp;
            master(dep+1);
        }
    }
}
int main(){
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    cin>>n;
    cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];

    memset(h,0,sizeof(h));
    fj(1);
    master(1);

    cout<<ans<<endl;
    return 0;
}
