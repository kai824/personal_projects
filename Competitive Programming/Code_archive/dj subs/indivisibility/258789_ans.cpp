// ans.cpp 16 Nov 17, 18:16:30 100 0.27 Judging completed in 7.499s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sieve[2525];
int ps[2525],u;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int x=2;x<=10;x++){
        sieve[x]=1;
        u=x+x;
        while(u<=2520){
            sieve[u]=1;
            u+=x;
        }
    }
    for(int x=1;x<=2520;x++){
        ps[x]=ps[x-1];
        if(sieve[x]==0){//x is not a multiple of those no.s
            ps[x]++;
        }
    }
    ll a,b;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        cout<<( (b/2520)*ps[2520] )+ ps[(b%2520)]<<'\n';
    }
    return 0;
}