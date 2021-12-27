// ans.cpp 24 Oct 17, 20:04:10 100 0 Judging completed in 6.075s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b,x,y,z;
    cin>>r>>b>>g;
    x=r+b-g;
    y=r+g-b;
    z=b+g-r;
    if(x<0|| (x%2)==1 || y<0 || (y%2)==1 || z<0 || (z%2)==1){
        cout<<"Impossible";
        return 0;
    }
    cout<<x/2<<' '<<y/2<<' '<<z/2;
    return 0;
}