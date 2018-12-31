/*
ID: hjl11841
TASK: namenum
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
string name[5000];
char ft[10][4]={{},{},"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
int main(){
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    int n=0;
    cin>>name[n];
    n++;
    freopen("dict.txt","r",stdin);
    while(cin>>name[n]) n++;
    string x=name[0];
    n--;
    bool none=1;
    for(int i=1;i<=n;i++){
        bool tmp=(name[i].size()==x.size());
        for(int j=0;j<name[i].size();j++){
            char c=name[i][j];
            tmp=tmp&(c==ft[x[j]-'0'][0]||c==ft[x[j]-'0'][1]||c==ft[x[j]-'0'][2]);
        }
        if(tmp){
            cout<<name[i].c_str()<<endl;
            none=0;
        }
    }
    if(none) cout<<"NONE"<<endl;
}
