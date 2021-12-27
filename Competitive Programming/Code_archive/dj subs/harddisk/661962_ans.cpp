// ans.cpp 23 Dec 19, 22:02:03 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef unsigned int ll;

vector<pair<ll,ll> > v,v1,v2;
vector<ll> vv1,vv2;
int main(){
    ll n,m,a,b,ans=0;long long sum,val;
    cin>>n>>m;
    for(ll x=0;x<20 && x<n;x++){
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
    for(ll x=1;x<(1<<(v1.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v1.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v1[i].first;
            val+=v1[i].second;
        }
        if(sum<=m){
            vv1.push_back(val);
            ans=max(ans,val);
        }
    }
    cout<<ans;
    return 0;
    for(ll x=1;x<(1<<(v2.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v2.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v2[i].first;
            val+=v2[i].second;
        }
        if(sum<=m){
            vv2.push_back(val);
            ans=max(ans,val);
        }
    }
    vv1.push_back(0);
    sort(vv1.begin(),vv1.end());
    ll lo,hi,mid;
    for(ll x=0;x<vv2.size();x++){
        lo=0;hi=vv1.size()-1;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(vv2[x]+vv1[mid]<=m){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        if(vv2[x]+vv1[lo]<=m)ans=max(ans,vv2[x]+vv1[lo]);
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