// ans.cpp 12 Nov 18, 14:14:44 76 1.08 Judging completed in 4.073s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3

typedef long long ll;
bool flag=0;

inline char gec()
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
    set<ll>ss;
    ll n=get(),ans=0;
    pair<ll,ll> arr[n];
    for(ll x=0;x<n;x++){
        arr[x].first=get();
        arr[x].second=x;
        if(flag)break;
    }
    sort(arr,arr+n,[](const pair<ll,ll>& a, const pair<ll,ll>& b)-> bool {return(a>b);});
    ss.insert(-1);ss.insert(n);
    for(ll x=0;x<n;x++){
        auto upper=ss.lower_bound(arr[x].second);
        auto lower=upper;
        lower--;
        ans+=*upper-*lower-2;;
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x].second);
    }
    cout<<ans;
    return 0;
}
//4 1 3 2 0