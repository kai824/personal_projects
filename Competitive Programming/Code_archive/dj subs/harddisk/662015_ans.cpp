// ans.cpp 23 Dec 19, 22:27:57 0 1 Judging completed in 5.373s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll,ll> > v1,v2;
//vector<pair<ll,ll> > vv1,vv2;
pair<ll,ll> v[1058576];//,vv1[1048576];
int main(){
    ll n,m,a,b,ans=0,sum,val,diff;
    cin>>n>>m;
    for(ll x=0;(x<n && x<20);x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        else continue;
        v1.push_back(make_pair(a,b));
    }
    for(ll x=20;x<n;x++){
        cin>>a>>b;//weight, value
        if(a<=m)ans=max(ans,b);
        else continue;
        v2.push_back(make_pair(a,b));
    }
    v[0]=(make_pair(0,0));
    ll nex2=1;
    for(ll x=0;x<(1<<(v1.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v1.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v1[i].first;
            val+=v1[i].second;
        }
        if(sum<=m){
            v[nex2]=make_pair(sum,val);nex2++;
            ans=max(ans,val);
        }
    }
    sort(v,v+nex2);
    diff=0;
    for(int x=1;diff+x<nex2;){
        v[x]=v[diff+x];
        if(v[diff+x-1].second>=v[diff+x].second){
            diff++;//remove current element...
        }else x++;
    }
    nex2-=diff;
    for(int x=1;x<nex2;x++){
        if(v[x-1].second>=v[x].second){
            while(true){};
        }
    }
    
    ll lo,hi,mid;
    for(ll x=0;x<(1<<(v2.size()));x++){
        sum=val=0;
        for(ll i=0;i<(v2.size());i++){
            if(((1<<i)&x)==0)continue;
            sum+=v2[i].first;
            val+=v2[i].second;
        }
        if(sum<=m){
            //vv2.emplace_back(sum,val);
            ans=max(ans,val);
            lo=0;hi=nex2-1;
            while(lo<hi){
                mid=lo+(hi-lo)/2;
                if(sum+v[mid].first<=m){
                    hi=mid;
                }else{
                    lo=mid+1;
                }
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