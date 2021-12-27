// ans.cpp 21 Oct 17, 10:57:23 0 0 Judging completed in 4.557s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b,sum,x,y,z;
    cin>>r>>b>>g;
    if((g+b+r)%2!=0|| r==1||g==1||b==1){
        cout<<"Impossible";
        return 0;
    }
    sum=(g+b+r)/2;//sum of all the answers...
    x=sum-g;
    y=sum-b;
    z=sum-r;
    if(x==0 || y==0||z==0){
        cout<<"Impossible";return 0;
    }
    cout<<x<<' '<<y<<' '<<z;
    return 0;
}