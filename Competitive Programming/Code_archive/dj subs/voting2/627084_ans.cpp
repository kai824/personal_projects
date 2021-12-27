// ans.cpp 4 Dec 19, 11:01:18 0 0.08 Judging completed in 4.128s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii arr[200005];
bool bought[200005];

bool cmp(pii a,pii b){
	if(a.first!=b.first){
		return(a.first<b.first);
	}
	return(a.second>b.second);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int tc,n,voters;
	long long ans=0;
	cin>>tc;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	while(tc--){
		cin>>n;
		for(int x=0;x<n;x++){
			cin>>arr[x].first>>arr[x].second;
			bought[x]=false;
		}
		sort(arr,arr+n,cmp);
		while(!pq.empty()){
			pq.pop();
		}
		ans=voters=0;
		for(int x=0;x<n;x++){
			pq.push(make_pair(arr[x].second,x));
		}
		for(int x=0;x<n;x++){
			while(voters<=arr[x].first && !pq.empty()){
				if(pq.top().second<=x){
					pq.pop();
					continue;
				}
				bought[pq.top().second]=true;
				ans+=pq.top().first;
				voters++;
				pq.pop();
			}
			if(voters<arr[x].first){//ran out of ppl to bribe...
				ans+=arr[x].second;
			}
			if(bought[x]==false)voters++;
		}
		cout<<ans<<'\n';
	}
    return 0;
}
/*
3
3
1 5
2 10
2 8
7
0 1
3 1
1 1
6 1
1 1
4 1
4 1
6
2 6
2 3
2 8
2 7
4 4
5 5
*/