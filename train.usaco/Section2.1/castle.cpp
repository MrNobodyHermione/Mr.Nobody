/*
ID: hjl11841
TASK: castle
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[60][60];
int b[110][110];
int ans=0;
int h[2510];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct wall{
	int wx;
	int wy;
	int key;
	char direction;
}w[10010];
bool Mycomp(const wall&x,const wall&y){
	if(x.key!=y.key) return x.key>y.key;
	if(x.wy!=y.wy) return x.wy<y.wy;
	if(x.wx!=y.wx) return x.wx>y.wx;
	if(x.direction=='N') return true;
	return false;
}
void dfs(int x,int y){
	b[x][y]=ans;
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(b[tx][ty]&&tx>0&&tx<n*2&&ty>0&&ty<m*2&&b[tx+dir[i][0]][ty+dir[i][1]]==0){
			h[ans]++;
			dfs(tx+dir[i][0],ty+dir[i][1]);
		}
	}
}
int main(){
  freopen("castle.in","r",stdin);
  freopen("castle.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	memset(b,1,sizeof(b));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=a[i][j];
			b[2*i-1][2*j-1]=0;
			if(x>=8){
				x-=8;
				b[2*i][2*j-1]=0;
			}
			if(x>=4){
				x-=4;
				b[2*i-1][2*j]=0;
			}
			if(x>=2){
				x-=2;
				b[2*i-2][2*j-1]=0;
			}
			if(x>=1){
				x-=1;
				b[2*i-1][2*j-2]=0;
			}
		}
	}
	
	for(int i=1;i<=2*n-1;i+=2){
		for(int j=1;j<=2*m-1;j+=2){
			if(b[i][j]==0){
				ans++;
				h[ans]++;
				dfs(i,j);
			}
		}
	}
	
	cout<<ans<<endl;
	int maxn=0;
	for(int i=1;i<=ans;i++){
		maxn=max(maxn,h[i]);
	}
	cout<<maxn<<endl;
	
	int wallnumber=0;
	for(int i=2*n-1;i>=1;i-=2){
		for(int j=1;j<=2*m-1;j+=2){
			if(i!=1&&j!=2*m-1){
				if(b[i-1][j]==0&&b[i][j]!=b[i-2][j]){
					w[++wallnumber].wx=(i+1)/2;
					w[wallnumber].wy=(j+1)/2;
					w[wallnumber].key=h[b[i][j]]+h[b[i-2][j]];
					w[wallnumber].direction='N';
				}
				if(b[i][j+1]==0&&b[i][j]!=b[i][j+2]){
					w[++wallnumber].wx=(i+1)/2;
					w[wallnumber].wy=(j+1)/2;
					w[wallnumber].key=h[b[i][j]]+h[b[i][j+2]];
					w[wallnumber].direction='E';
				}
			}
			else if(i==1&&j!=2*m-1){
				if(b[i][j+1]==0&&b[i][j]!=b[i][j+2]){
					w[++wallnumber].wx=(i+1)/2;
					w[wallnumber].wy=(j+1)/2;
					w[wallnumber].key=h[b[i][j]]+h[b[i][j+2]];
					w[wallnumber].direction='E';
				}
			}
			else if(i!=1&&j==2*m-1){
				if(b[i-1][j]==0&&b[i][j]!=b[i-2][j]){
					w[++wallnumber].wx=(i+1)/2;
					w[wallnumber].wy=(j+1)/2;
					w[wallnumber].key=h[b[i][j]]+h[b[i-2][j]];
					w[wallnumber].direction='N';
				}
			}
		}
	}
	
	sort(w+1,w+wallnumber+1,Mycomp);
	cout<<w[1].key<<endl;
	cout<<w[1].wx<<' '<<w[1].wy<<' '<<w[1].direction<<endl;
	return 0;
}
