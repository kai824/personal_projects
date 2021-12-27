// ans.cpp 21 Jan 19, 11:17:49 100 0.03 Judging completed in 1.954s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long min_ans=INT_MAX,n;
    cin>>n;
    long long arr[n],ps[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        if(x==0)ps[x]=arr[x];
        else ps[x]=ps[x-1]+arr[x];
    }
    for(int x=0;x<n-1;x++){
        min_ans=min(min_ans,abs(ps[n-1]-ps[x]-ps[x]));
    }
    cout<<min_ans;
    return 0;
}