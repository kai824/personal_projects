// ans.cpp 4 Dec 19, 11:12:36 0 0.08 Judging completed in 4.301s on AWS Oregon.
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
	priority_queue<pii,vector<pii>,greater<pii> > pq,pq2;
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
		while(!pq2.empty()){
		    pq2.pop();
		}
		ans=voters=0;
		for(int x=0;x<n;x++){
			pq.push(make_pair(arr[x].second,x));
		}
		for(int x=0;x<n;x++){
			if(bought[x])continue;
			while(voters<arr[x].first && !pq.empty()){
				if(pq.top().second<=x){
					pq.pop();
					continue;
				}
				if(arr[pq.top().second].first<=arr[x].first){
				    pq.pop();
				}
				bought[pq.top().second]=true;
				ans+=pq.top().first;
				voters++;
				pq.pop();
			}
			if(voters<arr[x].first){//ran out of ppl to bribe...
			    while(voters<arr[x].first && !pq2.empty()){
    				if(pq2.top().second<=x){
    					pq2.pop();
    					continue;
    				}
    				if(arr[pq2.top().second].first<arr[x].first){
    				    pq2.pop();
    				}
    				bought[pq2.top().second]=true;
    				ans+=pq2.top().first;
    				voters++;
    				pq2.pop();
    			}
				ans+=arr[x].second;
			}
			voters++;
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