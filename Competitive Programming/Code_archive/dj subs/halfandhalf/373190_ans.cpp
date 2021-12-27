// ans.cpp 27 Jun 18, 07:57:20 100 0 Judging completed in 4.138s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b,c,x,y,ans=0;
    cin>>a>>b>>c>>x>>y;
    if(x<y){
        swap(a,b);
        swap(x,y);
    }
    if(2*c>=a+b)ans=(a*x)+(b*y);
    else{
        ans+=2*c*y;
        x-=y;
        if(2*c<a)ans+=2*c*x;
        else ans+=a*x;
    }
    cout<<ans;
    return 0;
}