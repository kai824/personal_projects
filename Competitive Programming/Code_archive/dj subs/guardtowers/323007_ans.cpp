// ans.cpp 7 Feb 18, 20:40:49 76 2.37 Judging completed in 9.167s on AWS Oregon.
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
    cin.tie(0);
    set<int>ss;
    ll n=get(),ans=0;
    pair<int,int> arr[n];
    for(int x=0;x<n;x++){
        arr[x].first=get();
        arr[x].second=x;
        if(flag)break;
    }
    sort(arr,arr+n,[](const pair<int,int>& a, const pair<int,int>& b)-> bool {return(a>b);});
    ss.insert(-1);ss.insert(n);
    auto upper=ss.begin(),lower=ss.begin();
    for(int x=0;x<n;x++){
        upper=lower=ss.lower_bound(arr[x].second);
        lower--;
        ans+=*upper-*lower-2;
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x].second);
    }
    cout<<ans;
    return 0;
}
//4 1 3 2 0