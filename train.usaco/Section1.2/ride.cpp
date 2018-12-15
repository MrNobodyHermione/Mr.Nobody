/*
ID: hjl11841
TASK: ride
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
string ufo;
string group;
int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	cin>>ufo;
	cin>>group;
	
	int a,b;
	a=b=1;
	for(int i=0;i<ufo.size();i++){
		int tmp1;
		tmp1=ufo[i]-'A'+1;
		a*=tmp1;
	}
	for(int i=0;i<group.size();i++){
		int tmp2;
		tmp2=group[i]-'A'+1;
		b*=tmp2;
	}
	a%=47;
	b%=47;
	
	if(a==b) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}
