// ans.cpp 18 Dec 19, 18:10:21 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma O3

typedef __int128 ll;

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

int nex[5000005];
bool vis[5000005];

int dfs(int x,int dist){
	vis[x]=true;
	if(vis[nex[x]])return dist;
	return dfs(nex[x],dist+1);
}

inline ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

inline ll calc(ll a,ll b){
	return (a/gcd(a,b))*b;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	int n=get(),m=get();
	ll lcm=1;
	for(int x=1;x<=n;x++){
		nex[x]=get();
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			lcm=calc(lcm,dfs(x,1));
		}
	}
	cout<<(long long)(lcm%m);
    return 0;
}