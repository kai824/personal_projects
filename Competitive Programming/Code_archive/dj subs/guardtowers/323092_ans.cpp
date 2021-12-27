// ans.cpp 8 Feb 18, 09:06:48 76 2.49 Judging completed in 5.949s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    cin.tie(NULL);
    set<ll>ss;
    ll n=get(),ans=0;
    pair<ll,ll> arr[n];
    for(ll x=0;x<n;x++){
        arr[x].first=get();
        arr[x].second=x;
        if(flag)break;
    }
    sort(arr,arr+n,[](const pair<ll,ll>& a, const pair<ll,ll>& b)-> bool {return(a>b);});
    ss.insert(n);ss.insert(-1);
    for(ll x=0;x<n;x++){
        auto upper=ss.lower_bound(arr[x].second);
        auto lower=upper;
        lower--;
        ans+=*upper-*lower;
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x].second);
    }
    cout<<ans-(2*n);
}
//4 1 3 2 0