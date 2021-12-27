// ans.cpp 19 Oct 17, 10:58:45 0 0.2 Judging completed in 4.627s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m,tc,fib[10]={0,1,1,2,3,5,8,13,21,34};
pair<ll,ll> query(ll a){
    if(a<9)return(make_pair(fib[a]%m,fib[a+1]%m));
    pair<ll,ll> prev;
    if((a%2)==0){
        prev=query(a/2);
        return(make_pair( (prev.first*((2*prev.second)-prev.first))%m , ((prev.first*prev.first)%m+((prev.second*prev.second%m)))%m ) );
    }else{
        prev=query((a-1)/2);
        prev=make_pair( (prev.first*((2*prev.second)-prev.first))%m , ((prev.first*prev.first)%m+((prev.second*prev.second%m)))%m );
        return(make_pair(prev.second,(prev.first+prev.second)%m));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        cout<<query(n).first<<'\n';
    }
    return 0;
}