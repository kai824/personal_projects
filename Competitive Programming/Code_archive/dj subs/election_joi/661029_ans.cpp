// ans.cpp 23 Dec 19, 12:55:30 10 0.05 Judging completed in 4.003s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[100005];
vector<pair<ll,ll> > v[100005];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,b,c,m;
    cin>>n;
    for(int x=1;x<n;x++){
        cin>>a>>b;
    }
    cin>>m;
    for(int x=0;x<m;x++){
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        v[b].push_back(make_pair(a,c));
    }
    for(int x=1;x<=n;x++){
        ans[x]=max(ans[x],ans[x-1]);
        for(int i=0;i<v[x].size();i++){
            ans[x]=max(ans[x],ans[v[x][i].first-1]+v[x][i].second );
        }
    }
    cout<<ans[n];
    return 0;
}
/*
8
1 2 2 3 3 4 4 5 5 6 6 7 7 8
5
7 5 4
5 8 9
4 3 9
1 3 3
2 8 11
*/