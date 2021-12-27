// ans.cpp 24 Feb 18, 15:52:09 11 0.3 Judging completed in 5.394s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,min_end=INT_MAX,max_start=INT_MIN,s,e,a;
    cin>>n>>k;
    if(k!=2)return 0;
    for(int x=0;x<n;x++){
        cin>>s>>e>>a;
        max_start=max(max_start,s);
        min_end=min(min_end,e);
    }
    if(max_start<min_end){
        cout<<"-1";return 0;
    }
    cout<<max_start-min_end;
    return 0;
}