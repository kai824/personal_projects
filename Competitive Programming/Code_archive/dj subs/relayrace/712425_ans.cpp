// ans.cpp 13 Mar 20, 18:43:57 100 0.39 Judging completed in 4.234s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;


#define int long long
#define mp make_pair
#define eb emplace_back
typedef pair<long long,long long> pii;

int d1[500005],d2[500005];
vector<pii> adjl[500005];
priority_queue<pii,vector<pii>,greater<pii> > dijk;

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
		int n,m,s,t,a,b,c;
		cin>>n>>m>>s>>t;
		for(int x=0;x<m;x++){
			cin>>a>>b>>c;
			adjl[a].eb(b,c);
			adjl[b].eb(a,c);
		}
		d1[s]=1;
		dijk.push(mp(1,s));
		while(!dijk.empty()){
			a=dijk.top().second;
			dijk.pop();
			for(int x=0;x<adjl[a].size();x++){
				if(d1[adjl[a][x].first]==0 || d1[adjl[a][x].first]>d1[a]+adjl[a][x].second){
					d1[adjl[a][x].first]=d1[a]+adjl[a][x].second;
					dijk.push(mp(d1[adjl[a][x].first],adjl[a][x].first));
				}
			}
		}
		d2[t]=1;
		dijk.push(mp(1,t));
		while(!dijk.empty()){
			a=dijk.top().second;
			dijk.pop();
			for(int x=0;x<adjl[a].size();x++){
				if(d2[adjl[a][x].first]==0 || d2[adjl[a][x].first]>d2[a]+adjl[a][x].second){
					d2[adjl[a][x].first]=d2[a]+adjl[a][x].second;
					dijk.push(mp(d2[adjl[a][x].first],adjl[a][x].first));
				}
			}
		}
		assert(d1[t]==d2[s]);
		int ans=LLONG_MAX;
		for(int x=1;x<=n;x++){
		    if(d1[x]==0||d2[x]==0)continue;
			ans=min(ans,max(d1[x]-1,d2[x]-1) );
		}
		cout<<ans<<'\n';
    return 0;
}