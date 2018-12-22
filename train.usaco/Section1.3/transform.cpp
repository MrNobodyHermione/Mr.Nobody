/*
ID: hjl11841
TASK: transform
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[20][20];
char b[20][20];
char c[20][20];
char d[20][20];
int n;
void rotation(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[j][n-i+1]=a[i][j];
        }
    }
}
void reflection(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][n-j+1]=d[i][j];
        }
    }
}
bool check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]!=c[i][j]) return false;
        }
    }
    return true;
}
void fuzhi(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=c[i][j];
        }
    }
}
int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }

    rotation();
    fuzhi();
    if(check()){
        cout<<1<<endl;
        return 0;
    }
    rotation();
    fuzhi();
    if(check()){
        cout<<2<<endl;
        return 0;
    }
    rotation();
    fuzhi();
    if(check()){
        cout<<3<<endl;
        return 0;
    }
    reflection();
    fuzhi();
    if(check()){
        cout<<4<<endl;
        return 0;
    }
    rotation();
    fuzhi();
    if(check()){
        cout<<5<<endl;
        return 0;
    }
    rotation();
    fuzhi();
    if(check()){
        cout<<5<<endl;
        return 0;
    }
    rotation();
    fuzhi();
    if(check()){
        cout<<5<<endl;
        return 0;
    }
    int flag=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]!=b[i][j]) flag=false;
        }
    }
    if(flag) cout<<6<<endl;
    else cout<<7<<endl;
    return 0;
}
