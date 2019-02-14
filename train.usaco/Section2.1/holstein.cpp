/*
ID: hjl11841
TASK: holstein
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std; 
int ans[10010];
int a[30];
int b[20][30];
int c[10010];
int n,m,cnt=100000000;
bool check(int x){
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=x;j++){
        	sum+=b[c[j]][i];
        }	
    	if(sum<a[i]) return false;
    }
    return true;
}
void search(int x,int y){
    if(x>m){
        if(check(y)){
            if(y<cnt){
                cnt=y;
                for(int i=1;i<=cnt;i++){
                    ans[i]=c[i];
                }
            }
        }
        return;
    }
    c[y+1]=x;
    search(x+1,y+1);
    c[y+1]=0;
    search(x+1,y);
}
int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
        	cin>>b[i][j];
        }
    }
    
    search(1,0);
    
    cout<<cnt<<' ';
    for(int i=1;i<cnt;i++){
    	cout<<ans[i]<<' ';
    }
    cout<<ans[cnt]<<endl;
    return 0;
}
