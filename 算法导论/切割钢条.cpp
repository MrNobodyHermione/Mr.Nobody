/*
ID: hjl11841
TASK: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int f[20][20]={0};
int a[20]={0,1,5,8,9,10,17,17,20,24,30};
int main(){
    for(int i=1;i<=10;i++){
        f[i][1]=a[1];
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(j<i) f[i][j]=f[i-1][j];
			else{
                for(int k=1;k<=i;k++){
                    f[i][j]=max(f[i-1][j],max(f[i-1][j-k]+a[k],f[i][j-k]+a[k]));
                }
            }
        }
    }

    for(int i=1;i<=10;i++){
        cout<<f[10][i]<<endl;
    }
    return 0;
}
