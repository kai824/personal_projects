// ans.cpp 11 Sep 19, 22:27:18 100 0 Judging completed in 4.414s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    map<ll,ll> mp;
    mp[1]=0;
    ll a,b,n,q,prev=0;
    cin>>n>>q;mp[n+1]=0;
    vector<ll> queries;
    for(int x=0;x<q;x++){
        cin>>a;
        if(a==1){
			cin>>b;
			b++;
            mp[1]+=1;
            if(mp.find(b)==mp.end())mp[b]=-1;
            else mp[b]--;
            queries.push_back(b);
        }else{
            mp[1]-=1;//undo the change
            if(mp.find(queries.back())==mp.end())mp[queries.back()]=1;//not supposed to happen
            else mp[queries.back()]++;
            queries.pop_back();
        }
    }
    a=0;//use as cur_sum
    b=0;//use as ans
    for(auto it=mp.begin();it!=mp.end();it++){
        if(a>0){
            b+=min(it->first,n+1)-prev;//ans
        }
        a+=it->second;//first is key, second is value
        prev=it->first;
    }
    cout<<b;
    return 0;
}