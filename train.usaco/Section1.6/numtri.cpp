/*
ID: hjl11841
TASK: numtri
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int f[1001][1001]={0};
int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		f[n][i]=a[n][i];
	}
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
		}
	}
	
	cout<<f[1][1]<<endl;
	return 0;
}
