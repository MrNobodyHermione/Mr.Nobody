/*
ID: hjl11841
TASK: preface
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int i[20],v[20],x[20],l[20],c[20],d[20],m[20],A[20];
int cnti,cntv,cntx,cntl,cntc,cntd,cntm;
void hermione(int voldemort,int num){
    cnti+=i[voldemort]*num;
    cntv+=v[voldemort]*num;
    cntx+=x[voldemort]*num;
    cntl+=l[voldemort]*num;
    cntc+=c[voldemort]*num;
    cntd+=d[voldemort]*num;
    cntm+=m[voldemort]*num;
    return;
}
int main(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    cin>>n;
    A[1]=1;i[1]=1;
    A[2]=4;i[2]=1;v[2]=1;
    A[3]=5;v[3]=1;
    A[4]=9;i[4]=1;x[4]=1;
    A[5]=10;x[5]=1;
    A[6]=40;x[6]=1;l[6]=1;
    A[7]=50;l[7]=1;
    A[8]=90;x[8]=1;c[8]=1;
    A[9]=100;c[9]=1;
    A[10]=400;c[10]=1;d[10]=1;
    A[11]=500;d[11]=1;
    A[12]=900;c[12]=1;m[12]=1;
    A[13]=1000;m[13]=1;
    
    for(int j=1;j<=n;j++){
        int tmp=j,malfoy=13;
        while(tmp){
            while(tmp<A[malfoy]) malfoy--;
            hermione(malfoy,tmp/A[malfoy]);
            tmp%=A[malfoy];
        }
    }
    
    if (cnti!=0) cout<<"I "<<cnti<<endl;
    if (cntv!=0) cout<<"V "<<cntv<<endl;
    if (cntx!=0) cout<<"X "<<cntx<<endl;
    if (cntl!=0) cout<<"L "<<cntl<<endl;
    if (cntc!=0) cout<<"C "<<cntc<<endl;
    if (cntd!=0) cout<<"D "<<cntd<<endl;
    if (cntm!=0) cout<<"M "<<cntm<<endl;
    return 0;
}
