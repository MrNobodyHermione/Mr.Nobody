/*
ID: hjl11841
TASK: gift1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct people{
    string name;
    int in;
    int out;
}p[20];
map<string,int> m;
int main(){
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
    int np;
    cin>>np;
    for(int i=1;i<=np;++i){
        cin>>p[i].name;
        m[p[i].name]=i;
    }
    
    for(int i=1;i<=np;++i){
        string t;
        cin>>t;
        int sum,num;
        cin>>sum>>num;
        if(num==0){
            p[m[t]].out=0.0;
            continue;
        }
        if(sum % num == 0) p[m[t]].out=sum;
        else p[m[t]].out=sum-sum%num;
        for(int i=1;i<=num;++i){
            string f;
            cin>>f;
            p[m[f]].in+=sum/num;
        }
    }
    for(int i=1;i<=np;++i){
        cout<<p[i].name<<" "<<p[i].in-p[i].out<<endl;;
    }
    return 0;
}
