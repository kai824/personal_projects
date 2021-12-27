// ans.cpp 20 Jul 19, 18:10:25 40 0.35 Judging completed in 3.584s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool activated[1000005];
int par[1000005],r[1000005];

int get_root(int x){
	if(par[x]==-1) return x;
	else par[x]=get_root(par[x]);
	return par[x];
}

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return(a>b);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,maxi=0,width,cur;
    cin>>n;
    pair<ll,ll> arr[n];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[x]=make_pair(a,x);
        par[x]=-1;
        r[x]=1;
    }
    sort(arr,arr+n,cmp);
    activated[arr[0].first]=true;
    maxi=arr[0].first;
    for(int x=1;x<n;x++){
        cur=arr[x].second;width=1;
        activated[cur]=true;
        if(cur>0 && activated[cur-1]){
            width+=r[get_root(cur-1)];
            r[cur]+=r[get_root(cur-1)];
            par[get_root(cur-1)]=cur;
        }
        if(cur+1<n && activated[cur+1]){
            width+=r[get_root(cur+1)];
            r[cur]+=r[get_root(cur+1)];
            par[get_root(cur+1)]=cur;
        }
        
        maxi=max(maxi,width*arr[x].first);
    }
	cout<<maxi;
    return 0;
}