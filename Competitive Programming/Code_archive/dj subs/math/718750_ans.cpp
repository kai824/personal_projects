// ans.cpp 1 Apr 20, 13:58:00 0 0.03 Judging completed in 3.891s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

bool sieve[1000005];
bool prime[1000005],marked[1000005];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,u,u2;
    for(int x=2;x<=1000000;x++){
        if(sieve[x]==false){
            prime[x]=true;
            u=x*2;
            while(u<=1000000){
                sieve[u]=true;
                u+=x;
            }
            u=10;
            while(u<=x)u*=10;
            u2=1;
            //upper bound for things to add behind
            while((x*u2)<1000000){
                for(int xx=(x*u2);xx<(x*u2)+u2;xx++){
                    for(int yy=0;xx+(yy*u)<1000000;yy++){
                        marked[xx + (yy*u)]=true;
                    }
                }
                u*=10;
                u2*=10;
                //x*=10;
            }
        }
    }
    cin>>n;
    for(int x=1;x<=n;x++){
        if(marked[x] || prime[x]){
            cout<<"Up\n";
            continue;
        }
        cout<<x<<'\n';
    }
    return 0;
}