// ans.cpp 16 Dec 19, 14:04:58 100 0.92 Judging completed in 5.053s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int cc[25][25],ans=INT_MAX;
int cost[1500000];
int bit_cnt[1500000];

inline int ccnt(int x){
    int ans=0;
	for(;x;ans++)x-=(x & (-x));
	return ans;
}

inline int cnt(int x){
    return bit_cnt[x];
}

int main(){
	int n,k,a,o;
	cin>>n>>k;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin>>cc[x][y];//cost of pouring from x to y...
		}
	}
	for(int x=0;x<(1<<n);x++){
		cost[x]=1e9;
		bit_cnt[x]=ccnt(x);
	}
	cost[(1<<n)-1]=0;//bitmask stores which glass contains water...
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(make_pair(0,(1<<n)-1));//dist, node...

	while(!pq.empty()){
		a=pq.top().second;//the node number...
		if(cost[a]<pq.top().first){
			pq.pop();continue;
		}
		if(cnt(a)==k){
			ans=min(ans,pq.top().first);
			pq.pop();
			break;
		}
		pq.pop();
		for(int x=0;x<n;x++){
			if((a&(1<<x))==0)continue;
			o=cost[a-(1<<x)];
			for(int y=0;y<n;y++){
				if((a&(1<<y))==0)continue;
				if(x==y)continue;
				if(cost[a-(1<<x)]>cost[a]+cc[x][y]){
					cost[a-(1<<x)]=cost[a]+cc[x][y];
				}
			}
			if(cost[a-(1<<x)]<o){
				pq.push(make_pair(cost[a-(1<<x)],a-(1<<x)));
			}
		}
	}
	cout<<ans;
	return 0;
}