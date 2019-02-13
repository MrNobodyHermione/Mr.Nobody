/*
ID: hjl11841
TASK: sort3
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int num[1010],cnt[4],a[4],n;
int main(){
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        cnt[num[i]]++;
    }
    
    for(int i=1;i<=cnt[1]+cnt[2];i++){
        if(num[i]==3){
            a[3]++;
        }
        else if(num[i]==2&&i<=cnt[1]){
            a[1]++;
        }
        else if(num[i]==1&&i>cnt[1]){
            a[2]++;
        }
    }
    
    cout<<a[3]+max(a[1],a[2])<<endl;
    return 0;
}
