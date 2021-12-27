// ans.cpp 19 Dec 19, 11:16:47 73 1.04 Judging completed in 27.648s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma O3

typedef long long ll;

int nex[5000005];
bool vis[5000005];
bool sieve[5000005];

int dfs(int x,int dist){
	vis[x]=true;
	if(vis[nex[x]])return dist;
	return dfs(nex[x],dist+1);
}

inline ll calc(ll a,ll b){
	return (a/__gcd(a,b))*b;
}

vector<pair<int,int> > v;//prime factors, the current one
set<int> s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,m,u,a;
	ll lcm=1;
	cin>>n>>m;
	for(int x=2;x*x<=n;x++){//find the primes within sqrt n
	    if(sieve[x]==false){
	        v.emplace_back(x,1);
	        u=2*x;
	        while(u*u<=n){
	            sieve[u]=true;
				u+=x;
	        }
	    }
	}
	for(int x=1;x<=n;x++){
		cin>>nex[x];
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			//lcm=calc(lcm,dfs(x,1));
			a=dfs(x,1);
			for(int i=0;i<v.size();i++){
			    while((a%v[i].second)==0){
			        v[i].second*=v[i].first;
			    }
			    while((a%v[i].first)==0){
			        a/=v[i].first;
			    }
			}
			if(s.find(a)==s.end()){
			    s.insert(a);
			}
		}
	}
	u=1;
	for(int x=0;x<v.size();x++){
	    u*=v[x].second/v[x].first;u%=m;
	}
	for(auto x=s.begin();x!=s.end();x++){
	    u*= *x;u%=m;
	}
	cout<<(long long)(u%m);
    return 0;
}