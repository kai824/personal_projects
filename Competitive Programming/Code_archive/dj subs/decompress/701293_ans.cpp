// ans.cpp 16 Feb 20, 22:49:58 100 0.05 Judging completed in 4.142s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[300005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,p1,p2;
    cin>>n>>k;
    for(int x=1;x<=n-k+1;x++){
        cin>>arr[x];
    }
    p2=1;
    p1=p2-k+1;
    deque<pair<int,int> > dq;
    dq.push_back(make_pair(arr[1],1));
    for(int x=1;x<=n;x++){
        cout<<dq[0].first;
        if(x<n)cout<<' ';
        p1++;p2++;
        while(dq.size()>0 && dq[0].second<p1){
            dq.pop_front();
        }
        if(p2>n-k+1)continue;
        while(dq.size()>0 && arr[p2]<=dq.back().first){
            dq.pop_back();
        }
        dq.push_back(make_pair(arr[p2],p2));
    }
    return 0;
}