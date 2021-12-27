// ans.cpp 10 Feb 18, 16:18:49 20 0.07 Judging completed in 40.563s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,vector<ll> > mp;
vector<ll> v;
set<ll>squares;
set<ll>::iterator it;
pair<ll,ll> pp;
pair<ll,ll> get_coords(ll num){
    ll n,nn,sqrtv,num2=num;
    it=squares.upper_bound(num2);
    nn=*it;
    it--;
    n=*it;
    sqrtv=(nn-n)/2;
    //cout<<num<<' ';
    if(num==n){
        if((n%2)==0){
            return(make_pair(sqrtv/2,(sqrtv/2)-1));
        }else return(make_pair(-(sqrtv/2),-(sqrtv/2)));
    }
    pair<ll,ll>ans;
    if((n%2)==0){
        //top or left...
        if(num<=n+sqrtv+1){//top
        //cout<<"top ";
            ans.first=sqrtv/2;ans.second=sqrtv/2;
            ans.first++;
            ans.first-=num-n;
        }else{
        //cout<<"left ";
            ans.second=sqrtv/2;ans.first=-(sqrtv/2);
            ans.second-=(num-(n+sqrtv+1));
        }
    }else{
        if(num<=n+sqrtv+1){//bottom
        //cout<<"bottom ";
            ans.first=-( (sqrtv/2) + 1);ans.second=ans.first;
            ans.first+=num-n;
        }else{//right
        //cout<<"right ";
            ans.second=-(sqrtv/2);ans.first=sqrtv/2;ans.second--;ans.first++;
            ans.second+=num-(n+sqrtv+1);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(ll x=0;x<1000000;x++){
        squares.insert(x*x);
        if(x*x>100000)break;
    }
    ll n,q,si,ei,s,e;
    pair<ll,ll>start,endi;
    char sc,ec;
    string a;
    cin>>n;
    cin>>a;
    for(ll x=0;x<a.length();x++){
        if(mp.find(a[x])==mp.end()){
            mp[a[x]]=v;
        }
        mp[a[x]].push_back(x);
    }
    cin>>q;
    while(q--){
        cin>>si>>sc>>ei>>ec;
        si--;
        ei--;
        map<char,vector<ll> >::iterator it=mp.find(sc);
        s=((si/(it->second.size()))*n)  +  it->second[(si%it->second.size())]+1;
        it=mp.find(ec);
        e=((ei/(it->second.size()))*n)  +  it->second[(ei%it->second.size())]+1;
        start=get_coords(s);
        endi=get_coords(e);
        cout<<abs(start.first-endi.first)  +  abs(start.second-endi.second)<<'\n';
    }
    return 0;
}