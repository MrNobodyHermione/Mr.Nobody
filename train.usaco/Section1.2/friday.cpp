/*
ID: hjl11841
TASK: friday
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[7];
int tianshu(int y,int m){
	switch(m){
		case 4: case 6: case 9: case 11:{
			return 30;
			break;
		}
		case 2:{
			if(y%400==0||(y%100&&y%4==0)){
				return 29;
			}
			else return 28;
			break;
		}
		default:{
			return 31;
			break;
		}
	}
}
int main(){
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int n;
	cin>>n;
	
	int p=1;
	for(int i=1900;i<=1900+n-1;i++){
		for(int j=1;j<=12;j++){
			a[(p+12)%7]++;
			p+=tianshu(i,j);
		}
	}
	
	cout<<a[6];
	for(int i=0;i<6;i++){
		cout<<' '<<a[i];
	}
	cout<<endl;
	return 0;
}
