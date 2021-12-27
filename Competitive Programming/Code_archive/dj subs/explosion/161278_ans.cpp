// ans.cpp 12 Nov 16, 09:48:24 0 0.62 Judging completed in 6.953s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d,e;
    cin>>c>>a>>b;
    int g[c];
    for(int f=0;f<c;f=f+1){
        cin>>d>>e;
        g[f]=abs(d-a)+abs(e-b);
    }
    for(int f=0;f<c;f=f+1){
        cout<<g[f];
        if(f+1<c)cout<<" ";
    }
    return 0;
}