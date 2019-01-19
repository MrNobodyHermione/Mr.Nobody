/*
ID: hjl11841
TASK: skidesign
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int ans=INT_MAX;
    sort(a+1,a+n+1);
    for(int i=1;i<=a[n];i++){
        int cnt=0;
        int lowest=i;
        int highest=i+17;
        for(int j=1;j<=n;j++){
            if(a[j]<lowest) cnt+=(lowest-a[j])*(lowest-a[j]);
            if(a[j]>highest) cnt+=(a[j]-highest)*(a[j]-highest);
        }
        ans=min(ans,cnt);
    }

    cout<<ans<<endl;
    return 0;
}
