/*
ID: hjl11841
TASK: subset
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010]={0};
int n;
int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    cin>>n;

    int x=((1+n)*n)/2;
    if(x%2){
        cout<<0<<endl;
        return 0;
    }
    x/=2;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=x;j>=i;j--){
            dp[j]+=dp[j-i];
        }
    }

    cout<<dp[x]/2<<endl;
    return 0;
}
