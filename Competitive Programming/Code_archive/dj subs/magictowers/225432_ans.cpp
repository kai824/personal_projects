// ans.cpp 21 Oct 17, 10:55:47 0 0 Judging completed in 5.624s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b,sum;
    cin>>r>>b>>g;
    if((g+b+r)%2!=0|| r==1||g==1||b==1){
        cout<<"Impossible";
        return 0;
    }
    sum=(g+b+r)/2;//sum of all the answers...
    cout<<sum-g<<' '<<sum-b<<' '<<sum-r;
    return 0;
}