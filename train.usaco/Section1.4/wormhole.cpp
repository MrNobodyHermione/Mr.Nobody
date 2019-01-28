/*
ID: hjl11841
TASK: wormhole
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct jesus{
    int x,y;
}s[50];
int b[233],n,ans;
bool Mycomp(const jesus&a,const jesus&b){
    if(a.y<b.y) return true;
    if(a.y==b.y){
    	if(a.x<b.x) return true; 
    } 
    return false;
}
bool huan(int num,int x,int begin,int into){
    if(num!=1&&x==begin&&into==0){
        return true;
    }
    if(into==0){
        if(s[x].y==s[x+1].y){
            return huan(num+1,x+1,begin,1);
        }else return false;
    }
    if(into==1){
        return huan(num+1,b[x],begin,0);
    }
}
bool check(){
    for(int i=1;i<=n;i++){
        if(huan(1,i,i,0) ==1) return true;
    }
    return false;
}
void makepair(int x){
    int i,j;
    if(x==n+1){
        if(check()) ans++;
        return ;
    }
    if(b[x]==0){
        for(i=x+1;i<=n;i++){
            if(b[i]==0){
                b[x]=i;
                b[i]=x;
                makepair(x+1);
                b[x]=0;
                b[i]=0;
            }
        }	
    }else{
        makepair(x+1);
    }
    return ;
}
int main(){
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y;
    sort(s+1,s+1+n,Mycomp);
    makepair(1);
    cout<<ans<<endl;
    return 0;
}
