// ans.cpp 16 Dec 19, 10:29:39 20 0.17 Judging completed in 3.663s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int cc[25][25];
int dist[25],use[25];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k,cnt,a,cur,ans=INT_MAX,i;
	cin>>n>>k;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin>>cc[y][x];
		}
	}
	priority_queue<pii,vector<pii>,greater<pii> >pq;//dist, node number (0-indexed...)
	for(int x=1;x<(1<<n);x++){
		cnt=0;
		for(i=0;i<n;i++){
			if((x&(1<<i))>0)cnt++;
		}
		if(cnt!=k)continue;
		//pq.clear();
		while(!pq.empty()){pq.pop();}
		for(int y=0;y<n;y++){
			i=(1<<y);
			if(x&i){
				pq.push(make_pair(0,y));
				dist[y]=0;
				use[y]=0;
			}else dist[y]=use[y]=INT_MAX;
		}

		while(!pq.empty()){
			a=pq.top().second;
			if(pq.top().first>dist[a]){//searched elsewhere...
				pq.pop();
				continue;
			}
			pq.pop();
			for(i=0;i<n;i++){
				if(a==i)continue;
				if(dist[i]>dist[a]+cc[i][a]){
					dist[i]=dist[a]+cc[i][a];
					use[i]=cc[i][a];
					pq.push(make_pair(dist[i],i));
					//cout<<"yay\n";
				}
			}
		}//cout<<'\n';

		cur=0;
		for(int i=0;i<n;i++){
			//cout<<dist[i]<<' ';
			cur+=use[i];
		}//cout<<'\n';
		ans=min(ans,cur);


	}
	cout<<ans;
	return 0;
}
/*
5 2
0 5 4 3 2
7 0 4 4 4
3 3 0 1 2
4 3 1 0 5
4 5 5 5 0
*/