// ans.cpp 19 Dec 19, 20:51:25 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("axv2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;

int nex[5000050];
bitset<5000005> vis;
bitset<5000005> sieve;
bitset<5000005> used;

inline int dfs(int x){
    int ans=1;
    vis[x]=1;
    while(true){
        x=nex[x];
        if(vis[x]==1)return ans;
        vis[x]=1;
        ans++;
    }
    return ans;
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

vector<pair<int,short int> > v;//prime factors, the current one
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,m,u,a,maxi=0;short int cnt;
	ll lcm=1;
	n=get();m=get();
	
	int i,x;
	for(x=1;x<=n;x++){
		nex[x]=get();
	}
	/*for(int x=1;x<=n;x++){
		if(vis[x]==0){
			//lcm=calc(lcm,dfs(x,1));
			a=(dfs(x,1));
			maxi=max(maxi,a);
		}
	}
	for(int x=1;x<=n;x++){
		vis[x]=0;
	}*/
	for(x=2;x*x<=n;x++){//find the primes within sqrt n
	    if(sieve[x]==0){
	        v.emplace_back(x,0);
	        u=x<<1;
	        while(u*u<=n){
	            sieve[u]=1;
				u+=x;
	        }
	    }
	}
	u=1;
	for(x=1;x<=n;x++){
	    if(vis[x]==0){
	        a=dfs(x);
	        for(i=0;i<v.size();i++){
	            cnt=0;
	            while((a%v[i].first)==0){
			        a/=v[i].first;
			        cnt++;
			    }
			    v[i].second=max(v[i].second,cnt);
			}
			if(used[a]==0){
			    used[a]=1;
			    u*=a;u%=m;
			}
	    }
	}
	for(x=0;x<v.size();x++){
	    for(i=0;i<v[x].second;i++){
	        u*=v[x].first;
	        u%=m;
	    }
	    //u*=v[x].second/v[x].first;u%=m;
	}
	cout<<(long long)(u%m);
    return 0;
}