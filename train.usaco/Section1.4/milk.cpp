/*
ID: hjl11841
TASK: milk
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct jesus{
	int price;
	int ml;
}a[5010];
bool Mycomp(const jesus&x,const jesus&y){
	return x.price<y.price;
}
int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].price>>a[i].ml;
	}
	
	sort(a+1,a+n+1,Mycomp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t>a[i].ml){
			ans+=a[i].ml*a[i].price;
			t-=a[i].ml;
		}
		else{
			ans+=a[i].price*t;
			break;
		}
	}
	
	cout<<ans<<endl;
    return 0;
}
