/*
ID: hjl11841
TASK: crypt1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool num[15];
int n;
int ans=0;
bool jesus(int x){
    while(x){
        if(num[x%10]==0){
            return false;
        }
        x/=10;
    }
    return true;
}
bool check(int x,int y){
    int a=x*(y%10);
	int b=x*(y/10);
	int ji=x*y;
    if(a>999||b>999||ji>9999) return false;
    if(jesus(x)==1&&jesus(y)==1&&jesus(a)==1&&jesus(b)==1&&jesus(ji)==1) return true;
    return false;
}
int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        num[x]=true;
    }
    
    for(int i=100;i<1000;i++){
        for(int j=10;j<100;j++){
            if(check(i,j)) ans++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
