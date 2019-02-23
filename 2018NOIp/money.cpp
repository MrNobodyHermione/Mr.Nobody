#include<bits/stdc++.h>
using namespace std;
int a[110];
int f[25010];
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int ans=1;
        int tmp=ans;
        memset(f,0,sizeof(f));
        f[a[1]]=1;
        for(int i=a[1]+1;i<=a[n];i++){
            for(int j=1;j<=tmp;j++){
                if(f[i-a[j]]) f[i]=1;
            }
            if(i==a[tmp+1]&&!f[i]){
                ans++;
                tmp++;
                f[a[tmp]]=1;
            }
            else if(i==a[tmp+1]) tmp++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
