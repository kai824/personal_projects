// ans.cpp 8 Feb 17, 09:20:20 100 0 Judging completed in 2.683s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    int b[a],c,d,e;
    for(int x=0;x<a;x++){
        b[x]=x;
    }
    cin>>c;
    for(int x=0;x<c;x++){
        cin>>d>>e;
        swap(b[d],b[e]);
    }for(int x=0;x<a;x++){
        cout<<b[x]<<'\n';
    }
    return 0;
}