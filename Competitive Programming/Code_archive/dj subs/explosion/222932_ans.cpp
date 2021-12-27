// ans.cpp 16 Oct 17, 22:53:30 58 0.24 Judging completed in 6.215s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return(a.second<b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,aa,bb;
    cin>>n>>a>>b;
    pair<int,int> arr[n];
    for(int x=0;x<n;x++){
        arr[x].first=x+1;
        cin>>aa>>bb;
        arr[x].second=abs(a-aa)+abs(b-bb);
    }
    stable_sort(arr,arr+n,cmp);
    for(int x=0;x<n;x++){
        cout<<arr[x].first;
        if((x+1)<n)cout<<' ';
    }
    return 0;
}