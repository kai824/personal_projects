// ans.cpp 4 Feb 19, 15:18:10 0 0 Judging completed in 1.88s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    bool dir[4];//n,s,e,w
    string a;
    cin>>a;
    for(int x=0;x<a.length();x++){
        if(a[x]=='N')dir[0]=1;
        if(a[x]=='S')dir[1]=1;
        if(a[x]=='E')dir[2]=1;
        if(a[x]=='W')dir[3]=1;
    }
    if( (dir[0]^dir[1])==false && (dir[2]^dir[3])==false){
        cout<<"Yes";
    }else cout<<"No";
    return 0;
}