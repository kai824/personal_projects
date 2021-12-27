// ans.cpp 3 Dec 16, 13:23:09 100 1.03 Judging completed in 10.311s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,e,i,a,b,i1,w,start,end,u,ywh=INT_MAX,sum=0;

    cin>>n>>e>>start>>end;
 vector < vector <pair<int,int> > > graph(n+1,vector<pair<int, int> >());
int dist[99999];
fill_n(dist,99999,INT_MAX);

priority_queue<pair<int, int>,
			   vector<pair<int, int> >,
			   greater<pair<int, int> > > pq;
			   pq.push(make_pair(0,start));
			   dist[start] = 0;


    for (i=0;i<e;i++){
    	cin>>a>>b>>w;
    	graph[a].push_back(make_pair(b, w));
    
    	
    }
    while (!pq.empty()){
    	w=pq.top().first;
    	u=pq.top().second;
    	pq.pop();
	if (dist[u] >= w){
		dist[u] = w;
	
		for (i1=0;i1<graph[u].size();i1++){
			if ((dist[u] + graph[u][i1].second )< dist[graph[u][i1].first]) {
				dist[graph[u][i1].first] = dist[u] + graph[u][i1].second;
				pq.push(make_pair(dist[graph[u][i1].first], graph[u][i1].first));
			}
		}
	}

    }
        if (dist[end]==INT_MAX){
    	cout<<"-1"<<endl;
    	return 0;
    }
    sum+=dist[end];
    fill_n(dist,99999,INT_MAX);
    dist[end]=0;
    pq.push(make_pair(0,end));
    while (!pq.empty()){
    	w=pq.top().first;
    	u=pq.top().second;
    	pq.pop();
	if (dist[u] >= w){
		dist[u] = w;
	
		for (i1=0;i1<graph[u].size();i1++){
			if ((dist[u] + graph[u][i1].second )< dist[graph[u][i1].first]) {
				dist[graph[u][i1].first] = dist[u] + graph[u][i1].second;
				pq.push(make_pair(dist[graph[u][i1].first], graph[u][i1].first));
			}
		}
	}

    }
    if (dist[start]==INT_MAX){
    	cout<<"-1"<<endl;
    	return 0;
    }
   sum+=dist[start];
    cout<<sum<<endl;
}