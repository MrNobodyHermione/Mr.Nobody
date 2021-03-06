/*
ID: hjl11841
TASK: palsquare
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int b;
int a[1000];
char g[12]={'A','B','C','D','E','F','G','H','I','J','K','L'};
bool check(int x){
    int st=1,tail=1;
    while(x!=0){
        a[tail]=x%b;
        x=x/b;
        tail++;
    }
    tail--;
    for(int i=1;i<=(tail+1)/2;i++){
        if(a[i]!=a[tail+1-i]){
            st=0;
            break; 
        }
    } 
    if(st==1) return true;
    else return false;
}
void shuchu(int x){
    int tail=1;
    while(x!=0){
        a[tail]=x%b;
        x=x/b;
        tail++;
    }
    tail--;
    for(int i=tail;i>=1;i--){ 
        if(a[i]<=9) cout<<a[i];
        else cout<<g[a[i]-10];
    }
} 
int main() {
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    cin>>b;
    for(int i=1;i<=300;i++){
        if(check(i*i)){
            shuchu(i);
            cout<<' ';
            shuchu(i*i);
            cout<<endl;
        }
    }
    return 0;
}