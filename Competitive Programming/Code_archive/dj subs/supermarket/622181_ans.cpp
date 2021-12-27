// ans.cpp 2 Dec 19, 14:32:07 0 0.06 Judging completed in 5.132s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    int ps[n+1],w[n+1];ps[0]=w[0]=0;
    for(int x=1;x<=n;x++){
        cin>>ps[x];
        ps[x]+=ps[x-1];
    }
    for(int x=1;x<=n;x++){
        cin>>w[x];
        w[x]+=w[x-1];
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;//prefix reward, weight...
    for(int x=1;x<=n;x++){
        while(!pq.empty()){
            if(w[x]-pq.top().second>k){
                pq.pop();
            }
        }
        if(!pq.empty())ans=max(ans,ps[x]-pq.top().first);
    }
    cout<<ans;
    return 0;
}