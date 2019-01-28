/*
ID: hjl11841
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int c[1000002]={0};
int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int start=2e9,end=-2e9;
    int n;
    int a,b;
    int tf=1;
    int t[2]={0};
    int nstart;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        c[a]++;
        c[b]--;
        start=min(start,a);
        end=max(end,b-1);
    }
    nstart=start;
    int nc;
    end++;
    for(int i=start;i<=end;i++){
        c[i]=c[i-1]+c[i];
        nc=c[i]==0?0:1;
        if(nc!=tf||i==end){
            t[tf]=max(t[tf],i-nstart);
            nstart=i;
            tf=1-tf;
        }
    }
    cout<<t[1]<<' '<<t[0]<<endl;
    return 0;
}
