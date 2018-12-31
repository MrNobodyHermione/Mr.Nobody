/*
ID: hjl11841
TASK: barn1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int M,S,C,ans;
int a[10010],b[10010];
bool Mycomp(int x,int y){
	return x>y;
}
int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
	cin>>M>>S>>C;
	for(int i=1;i<=C;i++){
		cin>>a[i];
	}
	
	if(M>C){
		cout<<C<<endl;
		return 0;
	}
	sort(a+1,a+C+1);
	ans=a[C]-a[1]+1;
	for(int i=2;i<=C;i++){
		b[i-1]=a[i]-a[i-1];
	}
	sort(b+1,b+C,Mycomp);
	for(int i=1;i<M;i++){
		ans=ans-b[i]+1;
	}
	
	cout<<ans<<endl;
	return 0;
}
