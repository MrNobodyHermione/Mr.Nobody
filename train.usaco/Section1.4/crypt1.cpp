/*
ID: hjl11841
TASK: crypt1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[20];
int b[20];
int ans=0;
bool jesus(int x){
    while(x){
        int tmp=x%10;
        x/=10;
        int flg=false;
        for(int i=1;i<=n;i++){
            if(tmp==a[i]) flg=true;
        }
        if(!flg) return false;
    }
    return true;
}
bool check(){
    int chengshu1=b[1]*100+b[2]*10+b[3];
    int ji1=chengshu1*b[4];
    int ji2=chengshu1*b[5];
    int ji=ji1*10+ji2;
    if(ji1<100||ji1>999||ji2<100||ji2>999||ji<1000||ji>9999) return false;
    if(!jesus(ji)||!jesus(ji1)||!jesus(ji2)) return false;
    return true;
}
void cryptarithm(int dep){
    if(dep>5){
        if(check()) ans++;
        return;
    }
    for(int i=1;i<+n;i++){
        b[dep]=a[i];
        cryptarithm(dep+1);
    }
}
int main(){
    // freopen("crypt1.in","r",stdin);
    // freopen("crypt1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    cryptarithm(1);

    cout<<ans<<endl;
    return 0;
}
