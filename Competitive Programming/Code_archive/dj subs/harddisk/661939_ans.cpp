// ans.cpp 23 Dec 19, 21:54:40 0 1.01 Judging completed in 5.293s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef unsigned int ll;

vector<pair<ll,ll> > v,v1,v2;
vector<pair<ll,ll> > vv1,vv2;
int main(){
    ll n,m,a,b,ans=0,sum,val;
    cin>>n>>m;
    for(ll x=0;(x<n && x<20);x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        else continue;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    v1.push_back(v[0]);
    for(ll x=1;x<v.size();x++){
        v1.push_back(v[x]);//no point taking something with more space and without more value...
    }
    v.clear();
    for(ll x=20;x<n;x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        else continue;
        v.push_back(make_pair(a,b));
    }
    if(v.size()>0){
        sort(v.begin(),v.end());
        v2.push_back(v[0]);
        for(ll x=1;x<v.size();x++){
            v2.push_back(v[x]);//no point taking something with more space and without more value...
        }
    }
    v.clear();
    v.push_back(make_pair(0,0));
    for(ll x=1;x<(1<<(v1.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v1.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v1[i].first;
            val+=v1[i].second;
        }
        if(sum<=m){
            v.emplace_back(sum,val);
            ans=max(ans,val);
        }
    }
    sort(v.begin(),v.end());
    vv1.push_back(v[0]);
    for(int x=1;x<v.size();x++){
        vv1.push_back(v[x]);
        if(vv1[vv1.size()-2].second>=vv1.back().second){
            vv1.pop_back();
        }
    }
    for(ll x=1;x<(1<<(v2.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v2.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v2[i].first;
            val+=v2[i].second;
        }
        if(sum<=m){
            vv2.emplace_back(sum,val);
            ans=max(ans,val);
        }
    }
    ll lo,hi,mid;
    for(ll x=0;x<vv2.size();x++){
        lo=0;hi=vv1.size()-1;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(vv2[x].first+vv1[mid].first<=m){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        ans=max(ans,vv2[x].second+vv1[lo].second);
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