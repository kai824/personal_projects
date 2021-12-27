// ans.cpp 5 Dec 17, 11:40:09 0 0.02 Judging completed in 2.897s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnts[25];
int lengths[300005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    long long ans;
    string a;
    cin>>n>>k;
    for(int x=0;x<k;x++){
        cin>>a;
        lengths[x]=a.length();
        ans+=cnts[a.length()];
        cnts[a.length()]++;
    }
    for(int x=k;x<n;x++){
        cin>>a;
        lengths[x]=a.length();
        ans+=cnts[a.length()];
        cnts[a.length()]++;
        cnts[lengths[x-k]]--;
    }
    cout<<ans;
    return 0;
}