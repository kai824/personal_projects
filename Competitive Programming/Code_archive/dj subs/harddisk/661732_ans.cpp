// ans.cpp 23 Dec 19, 17:51:09 0 1.01 Judging completed in 5.527s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll,ll> > v,v1,v2;
vector<pair<ll,ll> > vv1;
int main(){
    ll n,m,a,b,ans=0,sum,val;
    cin>>n>>m;
    for(int x=0;x<min(20ll,n);x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        else continue;
        v1.push_back(make_pair(a,b));
    }
    for(int x=20;x<n;x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        else continue;
        v2.push_back(make_pair(a,b));
    }
    for(ll x=1;x<(1<<(v1.size()));x++){
        sum=val=0;
        for(int i=0;i<(v1.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v1[i].first;
            val+=v1[i].second;
        }
        if(sum<=m){
            vv1.push_back(make_pair(sum,val));
            ans=max(ans,val);
        }
    }
    vv1.push_back(make_pair(0,0));
    sort(vv1.begin(),vv1.end());
    v.clear();
    v.push_back(vv1[0]);
    for(int x=1;x<vv1.size();x++){
        if(v.back().second<vv1[x].second){
            v.push_back(vv1[x]);
        }
    }

    ll lo,hi,mid;

    for(ll x=1;x<(1<<(v2.size()));x++){
        sum=val=0;
        for(int i=0;i<(v1.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v2[i].first;
            val+=v2[i].second;
        }
        if(sum<=m){
            ans=max(ans,val);
            lo=0;hi=v.size()-1;
            while(lo<hi){
                mid=hi-(hi-lo)/2;
                if(sum+v[mid].first<=m){
                    hi=mid;
                }else lo=mid+1;
            }
            ans=max(ans,val+v[lo].second);
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