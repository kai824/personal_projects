// ans.cpp 8 Mar 18, 09:16:27 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=0;
set<ll>ss;
set<ll>::iterator upper;
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
ll n=get(),ans=-2*n;
pair<ll,ll> arr[n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    for(ll x=0;x<n;x++){
        arr[x].first=get();
        arr[x].second=x;
        if(flag)break;
    }
    sort(arr,arr+n,greater<pair<ll,ll> >());
    ss.insert(n);ss.insert(-1);
    for(ll x=0;x<n;x++){
        upper=ss.lower_bound(arr[x].second);
        ans+=*upper;
        upper--;
        ans-=*upper;
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x].second);
    }
    cout<<ans;
}
//4 1 3 2 0