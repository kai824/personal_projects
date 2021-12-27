// ans.cpp 19 Dec 19, 19:58:05 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma O3

typedef long long ll;

int nex[5000050];
bitset<5000005> vis;
bitset<5000005> sieve;

int dfs(int x,int dist){
	vis[x]=1;
	if(vis[nex[x]]==1)return dist;
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

vector<pair<int,short> > v;//prime factors, the current one

vector<int> v2,s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,m,u,a,cnt;
	ll lcm=1;
	n=get();m=get();
	for(int x=1;x<=n;x++){
		nex[x]=get();
		vis[x]=0;
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==0){
			//lcm=calc(lcm,dfs(x,1));
			v2.push_back(dfs(x,1));
		}
	}
	sort(v2.begin(),v2.end());
	for(int x=2;x*x<=v2.back();x++){//find the primes within sqrt n
	    if(sieve[x]==0){
	        v.emplace_back(x,1);
	        u=2*x;
	        while(u*u<=v2.back()){
	            sieve[u]=1;
				u+=x;
	        }
	    }
	}
	for(int x=0;x<v2.size();x++){
	    if(x==0 || v2[x]!=v2[x-1]){
	        a=v2[x];
	        for(int i=0;i<v.size();i++){
	            cnt=0;
	            while((a%v[i].first)==0){
			        a/=v[i].first;
			        cnt++;
			    }
			    v[i].second=max(v[i].second,cnt);
			}
			s.push_back(a);
	    }
	}
	u=1;
	for(int x=0;x<v.size();x++){
	    for(int i=0;i<v[x].second;i++){
	        u*=v[x].first;
	        u%=mod;
	    }
	    //u*=v[x].second/v[x].first;u%=m;
	}
	sort(s.begin(),s.end());
	a=unique(s.begin(),s.end())-s.begin();
	for(int x=0;x<a;x++){
	    u*= s[x];u%=m;
	}
	cout<<(long long)(u%m);
    return 0;
}