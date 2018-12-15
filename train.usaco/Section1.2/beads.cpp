/*
ID: hjl11841
TASK: beads
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1060];
int h[350]={0};
int n;
int hermione(int x,char y){
	if(h[x%n]) return 0;
	h[x%n]=1;
	int t=1;
	for(int i=x-1;i>0;i--){
		if(a[i]==y&&!h[i%n]){
			h[i%n]=1;
			t++;
		}
		else if(y=='w'&&!h[i%n]){
			y=a[i];
			t++;
			h[i%n]=1;
		}
		else if(a[i]=='w'&&!h[i%n]){
			h[i%n]=1;
			t++;
		}
		else return t;
	}
	return t;
}
int voldemort(int x,char y){
	if(h[x%n]) return 0;
	h[x%n]=1;
	int t=1;
	for(int i=x+1;i<=3*n;i++){
		if(a[i]==y&&!h[i%n]){
			h[i%n]=1;
			t++;
		}
		else if(y=='w'&&!h[i%n]){
			y=a[i];
			t++;
			h[i%n]=1;
		}
		else if(a[i]=='w'&&!h[i%n]){
			h[i%n]=1;
			t++;
		}
		else return t;
	}
	return t;
}
int main(){
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n+1;i<=n*3;i++){
		a[i]=a[i-n];
	}
	
	int ans=0;
	for(int i=n+1;i<=n*2;i++){
		memset(h,0,sizeof(h));
		int cnt=0;
		cnt+=hermione(i-1,a[i-1]);
		cnt+=voldemort(i,a[i]);
		ans=max(ans,cnt);
	}
	
	cout<<ans<<endl;
	return 0;
}
