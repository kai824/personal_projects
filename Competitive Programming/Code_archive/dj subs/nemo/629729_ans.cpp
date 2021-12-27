// ans.cpp 4 Dec 19, 17:26:45 32 0.11 Judging completed in 5.743s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll parent[50000];
ll getr(ll x){
    if(parent[x]==-1)return x;
    parent[x]=getr(parent[x]);
    return parent[x];
}
inline void merge(ll a,ll b){
    a=getr(a);b=getr(b);
    if(a==b)return;
    parent[a]=b;
}
bool cmp(pair<pair<ll,ll>,pair<ll,ll> >a,pair<pair<ll,ll>,pair<ll,ll> >b){
    return a.first.second>b.first.second;
}
bool cmp2(pair<pair<ll,pair<bool,ll> >,pair<ll,ll> >a,pair<pair<ll,pair<bool,ll> >,pair<ll,ll> >b){
	return a>b;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,q,a1,a2,o,c,it,pause;
    bool broke;
    cin>>n>>m;
    pair<pair<ll,ll>,pair<ll,ll> >edges[m];
    for(ll x=0;x<m;x++){
        cin>>a1>>a2>>o>>c;
        edges[x].first=make_pair(o,c);
        edges[x].second=make_pair(a1,a2);
    }
    cin>>q;
    pair<pair<ll,pair<bool,ll> >,pair<ll,ll> > arr[q];//time,answer,it,the 2 nodes...
    for(ll x=0;x<q;x++){
        arr[x].first.second.second=x;
        cin>>arr[x].second.first>>arr[x].second.second>>arr[x].first.first;
    }
    sort(arr,arr+q);
    
    sort(edges,edges+m);
    for(ll x=0;x<n;x++){
        parent[x]=-1;
    }
    it=0;pause=q;
    for(ll x=0;x<q;x++){
        while(it<m && arr[x].first.first>=edges[it].first.first){
            merge(edges[it].second.first,edges[it].second.second);
            it++;
        }
        if(getr(arr[x].second.first)==getr(arr[x].second.second)){
            arr[x].first.second.first=true;
        }else arr[x].first.second.first=false;
        swap(arr[x].first.first,arr[x].first.second.second);
		//cout<<arr[x].first.second.second<<' '<<arr[x].first.second.first<<'\n';
		if(it>=m){
            pause=x+1;
            break;
        }
    }
    sort(edges,edges+m,cmp);it=0;
	sort(arr+pause,arr+q,cmp2);
    for(ll x=0;x<n;x++){
        parent[x]=-1;
    }
    for(ll x=pause;x<q;x++){
        broke=false;
        while(it<m && arr[x].first.first<=edges[it].first.second){
            merge(edges[it].second.first,edges[it].second.second);
			//cout<<"k "<<edges[it].first.second<<'\n';
            it++;
        }
        if(getr(arr[x].second.first)==getr(arr[x].second.second)){
            arr[x].first.second.first=true;
        }else arr[x].first.second.first=false;
        swap(arr[x].first.first,arr[x].first.second.second);
		//cout<<arr[x].first.second.second<<' '<<arr[x].first.second.first<<'\n';
    }
    sort(arr,arr+q);
    for(ll x=0;x<q;x++){
        if(arr[x].first.second.first){
            cout<<"Y\n";
        }else{
            cout<<"N\n";
        }
    }
    return 0;
}