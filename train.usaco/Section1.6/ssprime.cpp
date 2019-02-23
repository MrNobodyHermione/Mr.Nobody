/*
ID: hjl11841
TASK: sprime
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool prime(int x) {
	if(x<2)return false;
	for(int i=2; i<=sqrt(x); i++) {
		if(x%i==0)return false;
	}
	return true;
}
void dfs(int dep,int last) {
	if(dep>n) {
		if(prime(last))cout<<last<<endl;
		return;
	} else {
		for(int i=1; i<=9; i++) {
			if(prime(last*10+i)) {
				dfs(dep+1,last*10+i);
			}
		}
	}
}
int main() {
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	cin>>n;

	dfs(1,0);
	return 0;
}
