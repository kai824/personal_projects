// ans.cpp 11 Dec 16, 18:15:47 100 0.91 Judging completed in 5.403s on AWS Ireland.
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