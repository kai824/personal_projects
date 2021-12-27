// ballgame.cpp 31 Jan 19, 22:08:56 0 0.54 Judging completed in 3.845s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ft[2000000],nn;
inline ll ls(ll x){return (x & (-x));}
inline void update(ll p,ll v){
    for(;p<=nn;p+=ls(p)){
        ft[p]+=v;
        ft[p]%=1000000007;
    }
}
inline ll query(ll s, ll e){
    ll ans=0;
    for(;e;e-=ls(e)){
        ans+=ft[e];
        ans%=1000000007;
    }
	s--;
    for(;s;s-=ls(s)){
        ans-=ft[s];
        ans%=1000000007;
    }
    if(ans<0)ans+=1000000007;
    if(ans<0)while(true){};
    return ans;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return(a>b);
}
int ballgame(int n, int l, int d, int h[], int c[]) {
    pair<ll,ll> ppl[n];//height(to sort by), then coordinate
    pair<int,pair<int,int> > lr[n];//middle, left, right
    //stores discretised, left, middle and right values
    pair<int,pair<int,char> > red[3*n];//for discretisation
    long long ans=0,a;
	int dis=1;
    for(ll x=0;x<n;x++){
        ppl[x]=make_pair(h[x],x);
        red[3*x].first=max(c[x]-d,0);
        red[3*x].second=make_pair(x,'0');
        red[3*x + 1].first=c[x];
        red[3*x + 1].second=make_pair(x,'1');
        red[3*x + 2].first=min(c[x]+d,1000000000);
        red[3*x + 2].second=make_pair(x,'2');
    }
    nn=dis;
    sort(red,red+3*n);
    for(int x=0;x<3*n;x++){
        if(x>0 && red[x].first!=red[x-1].first)dis++;
        if(red[x].second.second=='0') lr[red[x].second.first].second.first=dis;
        else if(red[x].second.second=='1') lr[red[x].second.first].first=dis;
        else if(red[x].second.second=='2') lr[red[x].second.first].second.second=dis;
    }
    sort(ppl,ppl+n,cmp);
    update(lr[ppl[0].second].first,1);
    for(ll x=1;x<n;x++){
        a=query(max(lr[ppl[x].second].second.first,0),min(lr[ppl[x].second].second.second,dis));
        //so a will be no. of ways to reach student x
        update(lr[ppl[x].second].first,a);
        if(x==n-1){
            return ((int) (a%1000000007));
        }
    }
}