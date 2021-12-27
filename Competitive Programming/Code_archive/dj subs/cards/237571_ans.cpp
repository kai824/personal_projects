// ans.cpp 30 Oct 17, 22:10:48 100 0.82 Judging completed in 4.292s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[500005],n;
ll st[20][500005];//sparse table...

ll ipow(ll a,ll b){
    ll ans=1;
    for(ll x=0;x<b;x++){
        ans*=a;
    }
    return ans;
}

void init(){
    ll b=ceil(log2(n)),ppow=2;
    for(ll x=0;x<n;x++){
        st[0][x]=arr[x];
    }
    for(ll x=1;ppow<=n;x++){
        for(ll y=0;y+ppow-1<n;y++){
            st[x][y]=min(st[x-1][y],st[x-1][y+(ppow/2)]);
        }
        ppow*=2;//stores 2^x
    }
}
ll query(ll a, ll b) {
	ll l,k;
    l=b-a+1;
    k=log2(l);
    return min(st[k][a],st[k][a+l-ipow(2,k)]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll lo,hi,mid,a,b,ans=0;
    cin>>n;
    for(ll x=0;x<n;x++){
        cin>>arr[x];
    }
    init();
    for(ll x=0;x<n;x++){
        lo=0;hi=x;
        while(lo<hi){
        	mid=lo+hi;
            mid-=(lo+hi)/2;
            if(query(x-mid,x)==arr[x]/* && (mid==0 || query(x-mid,x-1)!=arr[x])*/){
                lo=mid;//mid is usable...
            }else{//mid is not usable...
                hi=mid-1;
            }
        }
        a=lo+1;
        
        lo=0;hi=n-x-1;
        while(lo<hi){
            mid=(lo+hi);
            mid-=(lo+hi)/2;
            if(query(x,x+mid)==arr[x] && (mid==0 || query(x+1,x+mid)!=arr[x])){
                lo=mid;//mid is usable...
            }else{//mid is not usable...
                hi=mid-1;
            }
        }
        b=lo+1;
        ans+=(a*b*arr[x]);
    }
    cout<<ans;
    return 0;
}