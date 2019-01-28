/*
ID: hjl11841
TASK: ariprog
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
bool Mycomp(int x,int y){
    return x>y;
}
struct jesus{
    int u,v;
}w[200010];
bool tmp(jesus x,jesus y){
    if(x.u!=y.u)return x.u<y.u;
    return x.v<y.v;
}
int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
    int i,j,k,n,m,sum=0,num=0;
    cin>>n>>m;
    for(i=0;i<=m;i++){
        for(j=0;j<=m;j++){
            if(b[i*i+j*j]==0)a[++sum]=i*i+j*j;
            b[i*i+j*j]=1;
        }
    }
    
    sort(a+1,a+sum+1,Mycomp); 
    for(i=1;i<=sum-n+1;i++){
        for(j=i+1;j<=sum-n+2;j++){
            int p=a[i]-a[j],q=n-2,t=a[j],flag=1;
            if(t-(n-2)*p<0)break;
            while(q){
                q--;
                t-=p;
                if(t<0){
                    flag=0;
                    break;
                }
                if(b[t]==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                w[++num].u=p;
                w[num].v=t;
            }
        }
    }
    
    if(num==0){
        cout<<"NONE"<<endl;
        return 0;
    }
    sort(w+1,w+num+1,tmp);
    for(i=1;i<=num;i++){
        cout<<w[i].v<<' '<<w[i].u<<endl;
    }
    return 0;
}
