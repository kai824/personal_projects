// ans.cpp 21 Oct 17, 11:04:06 0 0 Judging completed in 5.396s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b,sum;
    cin>>r>>b>>g;
    if(((g+b+r)%2)!=0||g==0||r==0||b==0){
        cout<<"Impossible";
        return 0;
    }
    sum=(g+b+r)/2;//sum of all the answers...
    cout<<sum-g<<' '<<sum-b<<' '<<sum-r;
    return 0;
}