/*
ID: hjl11841
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
char a[20][20];
char b[20][20];
char c[20][20];
char d[20][20];
int n;
void transformation(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[j][n-i+1]=c[i][j];
        }
    }
}
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }

    transformation();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<d[i][j];
        }
        cout<<endl; 
    }
    return 0;
}

