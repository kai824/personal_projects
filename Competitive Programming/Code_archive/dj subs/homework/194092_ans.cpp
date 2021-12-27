// ans.cpp 24 Feb 17, 12:20:55 100 0.82 Judging completed in 6.427s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a;
    int hws[a];
    for(int x=0;x<a;x++){
        cin>>b;
        hws[x]=b;
    }
    sort(hws,hws+a);
    for(int x=0;x<a;x++){
        cout<<hws[x];
        if(x+1!=a)cout<<' ';
    }
    cout<<endl;
    return 0;
}