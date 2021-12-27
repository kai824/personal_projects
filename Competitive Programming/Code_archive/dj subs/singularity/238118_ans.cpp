// ans.cpp 31 Oct 17, 17:59:14 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005],n;
ll st[23][1000005];//sparse table...
ll pow2[23];

ll gcd2(ll a, ll b){
    a%=b;
    if (a==0) return b;
    else return gcd2(b,a);
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    return gcd2(a,b);
}
ll f_log2(ll a){
    ll ans=0;
    while(a>=2){
        a/=2;
        ans++;
    }
    return ans;
}

void init(){
    ll ppow=2;
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
    ll k=f_log2(l);
    return gcd(st[k][a],st[k][b+1-pow2[k]]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    pow2[0]=1;//2^0 = 1
    for(int x=1;x<23;x++){
        pow2[x]=pow2[x-1]*2;
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
        if(query(x,lo)==1)ans++;
    }
    cout<<ans;
    return 0;
}