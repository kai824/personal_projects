#include "wiring.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second

#ifdef local
#define deb(x) cerr<<x<<'\n';
#define debl(label,x) cerr<<label<<": "<<x<<'\n';
#else
#define deb(x) ;
#define debl(label,x) ;
#endif

ll min_total_length(vector<int> r,vector<int> b){//r and b are sorted
	ll ans=0,it=0;
	vector<int> mm;//min cost for each b...
	if(r.size()>b.size())swap(b,r);
	priority_queue<pii,vector<pii>,greater<pii> > pq1,pq2;//pq1 for decreasing, pq2 for increasing
	//value at 0, point of turn
	for(int i=0;i<b.size();i++){
		int x=b[i];
		while(it+1<r.size() && abs(x-r[it])>=abs(x-r[it+1])){
			it++;
		}
		mm.push_back(abs(x-r[it]));
		ans+=mm.back();
		pq1.emplace(x-mm.back(),i);
	}
	it=0;//next point to insert to pq2
	for(int i=0;i<r.size();(i++)){
		while(it<b.size() && b[it]<=r[i]){
			pq2.emplace(-b[it]-mm[it],it);//it kinda not needed but wtv
			it++;
			deb("Converted")
		}
		while(!pq1.empty() && pq1.top().s<it)pq1.pop();
		if(pq1.empty()){
			deb("path 1")
			ans+=pq2.top().f+r[i];
			pq2.pop();continue;
		}
		if(pq2.empty()){
			deb("path 2")
			ans+=pq1.top().f-r[i];
			pq1.pop();
			continue;
		}
		if(pq1.top().f-r[i]>=pq2.top().f+r[i]){//if upward sloping stuff is smaller, just take them
			deb("path 3a")
			ans+=pq2.top().f+r[i];pq2.pop();
		}else if(pq1.size()>=r.size()-i){//enough pq2 stuff for the rest...
			deb("path 3b")
			ans+=pq1.top().f-r[i];pq1.pop();
		}else{
			deb("path 3c")
			ans+=pq2.top().f+r[i];pq2.pop();
		}
	}
	return ans;
}
