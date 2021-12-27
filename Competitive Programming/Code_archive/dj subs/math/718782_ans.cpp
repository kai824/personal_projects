// ans.cpp 1 Apr 20, 14:16:10 0 0.18 Judging completed in 3.264s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define int long long

bool sieve[1000005];
bool prime[1000005];

int powers[10]={1000000,100000,10000,1000,100,10};

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,u,u2;
    for(int x=2;x<1000000;x++){
        if(sieve[x]==false){
            prime[x]=true;
            u=x*2;
            while(u<1000000){
                sieve[u]=true;
                u+=x;
            }
        }
    }
    cin>>n;
    bool broke;
    for(int x=1;x<=n;x++){
        if(prime[x]){
            cout<<"Up\n";
            continue;
        }
        u=x;
        broke=false;
        while(u>0){
            u2=u;
            if(prime[u2])broke=true;
            for(int i=0;i<6;i++){
                u2%=powers[i];
                if(prime[u2])broke=true;
            }
            if(broke)break;
            u/=10;
        }
        if(broke){
            cout<<"Up\n";continue;
        }
        cout<<x<<'\n';
    }
    return 0;
}