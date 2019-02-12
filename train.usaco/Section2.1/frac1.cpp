/*
ID: hjl11841
TASK: frac1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> fengzi;
vector<int> fengmu;
int gcd(int x,int y){
	int s;
	while(x){
		s=y%x;
		y=x;
		x=s;
	}
	return y;
}
int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int n;
	cin>>n;
	
	fengzi.push_back(0);
	fengzi.push_back(1);
	fengmu.push_back(1);
	fengmu.push_back(1);
	for(int i=2;i<=n;i++){
		for(int j=0;j+1<fengmu.size();j++){
			if(fengmu[j]+fengmu[j+1]==i){
				int x=fengmu[j]+fengmu[j+1];
				int y=fengzi[j]+fengzi[j+1];
				fengmu.insert(fengmu.begin()+j+1,x);
				fengzi.insert(fengzi.begin()+j+1,y);
			}
		}
	}
	
	for(int i=0;i<fengmu.size();i++){
		if(gcd(fengzi[i],fengmu[i])==1){
			cout<<fengzi[i]<<'/'<<fengmu[i]<<endl;
		}
	}
    return 0;
}
