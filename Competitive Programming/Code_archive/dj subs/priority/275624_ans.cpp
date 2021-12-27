// ans.cpp 2 Dec 17, 14:09:28 100 4.96 Judging completed in 13.424s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,a,b,c,aa;
    cin>>n;
    map<ll,bool> mp;
    priority_queue<pair<ll,ll>/*stored, real*/>q1,q2,q3;
    for(ll x=0;x<n;x++){
        cin>>a;
        mp[a]=false;
        aa=a;
        q1.push(make_pair(a%13371337,a));
        b=0;c=0;
        while(a>0){
            b+=a%10;
            c*=10;
            c+=a%10;
            a/=10;
        }
        q2.push(make_pair(b,aa));
        q3.push(make_pair(c,aa));
    }
    cin>>k;
    for(ll x=0;x<k;x++){
        cin>>a;
        if(a==1){
            while(mp[q1.top().second]){
                q1.pop();
            }
            mp[q1.top().second]=true;
            cout<<q1.top().second<<'\n';
            q1.pop();
        }else if(a==2){
            while(mp[q2.top().second]){
                q2.pop();
            }
            mp[q2.top().second]=true;
            cout<<q2.top().second<<'\n';
            q2.pop();
        }else{
            while(mp[q3.top().second]){
                q3.pop();
            }
            mp[q3.top().second]=true;
            cout<<q3.top().second<<'\n';
            q3.pop();
        }
    }
    return 0;
}