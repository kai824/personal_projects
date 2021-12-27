// ans.cpp 4 Nov 17, 13:09:05 100 0 Judging completed in 6.096s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x,y,d=256,ans=0;
    cin>>x>>y;
    while(d>0){
        //check with x
        ans=ans*2;//also leftshift...
        if( (d&x) !=0){//that bit is 1...
            ans+=1;
        }
        //check with y
        ans=ans*2;
        if( (d&y) !=0){
            ans+=1;
        }
        d/=2;
    }
    cout<<ans;
    return 0;
}