#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int ans=0;
int f[50][50][50];
int lover[10010];
void dfs(int a,int b,int c){
    if (f[a][b][c]) return;f[a][b][c]=1;
    if (!a) lover[ans++]=c;
    dfs(max(0,a-(y-b)),min(y,b+a),c);
    dfs(max(0,a-(z-c)),b,min(z,c+a));
    dfs(min(a+b,x),max(0,b-(x-a)),c);
    dfs(a,max(0,b-(z-c)),min(z,c+b));
    dfs(min(a+c,x),b,max(0,c-(x-a)));
    dfs(a,min(y,b+c),max(0,c-(y-b)));
}
int main(){
    cin>>x>>y>>z;
    
    memset(f,0,sizeof(f));
	dfs(0,0,z);
    sort(lover,lover+ans);
	  
    for(int i=0;i<ans;i++){
		cout<<lover[i]<<' ';
	}
    return 0;
}
