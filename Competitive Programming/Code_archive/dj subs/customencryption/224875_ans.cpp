// ans.cpp 20 Oct 17, 13:45:17 100 0.06 Judging completed in 4.97s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string a;
    bool b=false;
    ll cur=0;
    cin>>a;
    a=a+" ";
    vector<pair<ll,ll> > v;
    for(ll x=0;x<a.length();x++){
        if(isdigit(a[x])==false && cur>0){
            v[v.size()-1].second=cur;
            cur=0;
        }
        
        if(isalpha(a[x])){
            v.push_back(make_pair(((ll)(a[x]))-96,1));
        }else if(isdigit(a[x])){
            cur*=10;
            cur+=(a[x]-'0');
        }else if(a[x]=='!'){
            v.push_back(make_pair(-1,-1));
        }
    }
    cur=0;//now used as ans...
    for(ll x=v.size()-1;x>=0;x--){
        if(v[x].first==-1 && v[x].second==-1){
            b=!b;
            continue;
        }
        if(b){
            v[x].first+=13;
            if(v[x].first>26)v[x].first-=26;
        }
        
        cur+=v[x].first*v[x].second;
    }
    cout<<cur;
    return 0;
}