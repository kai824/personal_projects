// ans.cpp 31 Oct 17, 17:08:39 31 1.19 Judging completed in 4.842s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005],n;
ll st[23][1000005];//sparse table...

ll gcd(ll a, ll b){
    if(a<b)swap(a,b);
    ll d=a%b;
    a=b;
    b=d;
    if (b==0) return a;
    else return gcd(a,b);
}

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
            st[x][y]=gcd(st[x-1][y],st[x-1][y+(ppow/2)]);
        }
        ppow*=2;//stores 2^x
    }
}
ll query(ll a, ll b) {
	ll l,k;
    l=b-a+1;
    k=log2(l);
    return gcd(st[k][a],st[k][a+l-ipow(2,k)]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    init();
    ll lo,hi,mid,ans=0;
    for(ll x=0;x<n;x++){
        lo=x;hi=n-1;
        while(lo<hi){//find smallest range where gcd!=1...
            mid=lo+hi;
            mid-=(lo+hi)/2;
            if(query(x,mid)!=1){//mid is too small...
                lo=mid;
            }else{//the gcd of the stuff is 1
                hi=mid-1;
            }
        }
        ans+=n-1-lo;
    }
    cout<<ans;
    return 0;
}