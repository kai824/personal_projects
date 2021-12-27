// ans.cpp 7 Feb 18, 19:51:17 54 1.04 Judging completed in 4.858s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return(a>b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<int>ss;
    int n,ans=0;
    cin>>n;
    pair<int,int> arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x].first;
        arr[x].second=x;
    }
    sort(arr,arr+n,cmp);
    ss.insert(-1);ss.insert(n);
    for(int x=0;x<n;x++){
        auto upper=ss.lower_bound(arr[x].second);
        auto lower=upper;
        lower--;
        ans+=(arr[x].second-1- *lower)+(*upper-1-arr[x].second);
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x].second);
    }
    cout<<ans;
    return 0;
}
//4 1 3 2 0