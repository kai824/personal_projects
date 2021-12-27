// ans.cpp 23 Dec 19, 23:03:24 100 0.22 Judging completed in 4.139s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll,ll> > v1,v2;
//vector<pair<ll,ll> > vv1,vv2;
pair<ll,ll> v[1058576];//,vv1[1048576];
bitset<1058576>marked;
int main(){
    ll n,m,a,b,ans=0,sum,val,prev;
    cin>>n>>m;
    for(ll x=0;(x<n && x<20);x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        v1.push_back(make_pair(a,b));
    }
    for(ll x=20;x<n;x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        v2.push_back(make_pair(a,b));
    }
    v[0]=(make_pair(0,0));
    ll nex2=1;
    for(ll x=0;x<(1LL<<(v1.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v1.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v1[i].first;
            val+=v1[i].second;
            if(sum>m)break;
        }
        if(sum<=m){
            v[nex2]=make_pair(sum,val);nex2++;
            ans=max(ans,val);
        }
    }
    sort(v,v+nex2);
    prev=0;
    for(int x=1;x<nex2;x++){
        if(v[prev].second>=v[x].second){
			marked[x]=1;
        }else{
			prev=x;
		}
    }
    prev=0;
	for(int x=0;x+prev<nex2;){
		v[x]=v[x+prev];
		if(marked[x+prev]==1)prev++;
		else x++;
	}
    nex2-=prev;
    
    ll lo,hi,mid;
    for(ll x=0;x<(1LL<<(v2.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v2.size());i++){
            if(((1LL<<i)&x)==0)continue;
            sum+=v2[i].first;
            val+=v2[i].second;
            if(sum>m)break;
        }
        if(sum<=m){
            //vv2.emplace_back(sum,val);
            ans=max(ans,val);
            lo=0;hi=nex2-1;
            if(sum+v[0].first>m)continue;
            while(lo<hi){
                mid=hi-(hi-lo)/2;
                if(sum+v[mid].first<=m){
                    lo=mid;
                }else{
                    hi=mid-1;
                }
            }
            if(sum+v[lo].first<=m)ans=max(ans,val+v[lo].second);
        }
    }
    cout<<ans;
    return 0;
}
/*
3 5
5 2
2 1
3 2
*/