/*
ID: hjl11841
TASK: hamming
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int n,b,d;
int ans[80],cnt;
bool check(int x,int y){
    int tmp=x^y;
	int anss=0;
    while(tmp>0){
        if(tmp%2==1) anss++;
        tmp>>=1;
    }
    if(anss>=d) return true;
    else return false;
}
bool jesus(int x){
    for(int i=1;i<=cnt;i++){
        if(check(x,ans[i])==0){
            return false;
        }
    }
    return true;
}
int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
    cin>>n>>b>>d;
    
    b=1<<b;
    ans[++cnt]=0;
    while(cnt<n){
        for(int i=ans[cnt]+1;i<=b;i++){
            if(jesus(i)){
				ans[++cnt]=i;
				break;
			}
        }
    }
    
    for(int i=1;i<=cnt;i++){
    	cout<<ans[i];
    	if(i%10==0) cout<<endl;
    	else if(i==cnt) cout<<endl;
    	else cout<<' ';
    }
    return 0; 
}
