// ans.cpp 19 Dec 19, 19:48:17 73 0.69 Judging completed in 6.584s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma O3

typedef long long ll;

int nex[5000005];
bool vis[5000005];
bool sieve[50000];

int dfs(int x,int dist){
	vis[x]=true;
	if(vis[nex[x]])return dist;
	return dfs(nex[x],dist+1);
}


bool flag=0;

inline char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}

vector<pair<int,int> > v;//prime factors, the current one
set<int> s;
vector<int> v2;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,m,u,a;
	ll lcm=1;
	n=get();m=get();
	for(int x=1;x<=n;x++){
		nex[x]=get();
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			//lcm=calc(lcm,dfs(x,1));
			v2.push_back(dfs(x,1));
		}
	}
	sort(v2.begin(),v2.end());
	for(int x=2;x*x<=v2.back();x++){//find the primes within sqrt n
	    if(sieve[x]==false){
	        v.emplace_back(x,1);
	        u=2*x;
	        while(u*u<=v2.back()){
	            sieve[u]=true;
				u+=x;
	        }
	    }
	}
	for(int x=0;x<v2.size();x++){
	    if(x==0 || v2[x]!=v2[x-1]){
	        a=v2[x];
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