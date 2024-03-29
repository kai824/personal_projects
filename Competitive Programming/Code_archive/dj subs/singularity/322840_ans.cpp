// ans.cpp 7 Feb 18, 08:28:10 44 1.19 Judging completed in 6.245s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005],n,sum;
ll st[23][1000005];//sparse table...
ll pow2[23];

ll gcd(ll a,ll b){
    return __gcd(a,b);
}
ll f_log2(ll a){
    ll ans=0;
    while(a>=2){
        a/=2;
        ans++;
    }
    return ans;
}
ll c_log2(ll a){
    return(f_log2(a)+1);
}

void init(){
    ll b=c_log2(n),ppow=2;
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
    k=f_log2(l);
    return gcd(st[k][a],st[k][a+l-pow2[k]]);
}
bool flag=0;
char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n=get();
    for(int x=0;x<n;x++){
        arr[x]=get();
        sum+=arr[x];
        if(flag)break;
    }
    if(sum==n){
    	cout<<(n*(n+1))/2;
    	return 0;
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