// ans.cpp 22 Feb 18, 10:07:22 0 3 Judging completed in 11.011s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool sieve[50005];
typedef long long ll;
vector<pair<ll,ll> > primes;
ll m=1000000007;
ll ipow(ll base, ll exponent) { 
    ll result = 1;                        
    while (exponent) {                        // while the exponent is still non-zero
        if (exponent%2==1) result *= base;       // if the p contains the current power of 2, 
                                                   // multiply result by base^(2^current_power)

        base *= base;                            // square the base to get the next power of 2
        base %= m;                  //mod the integer, so it doesn't overflow
        result %= m;         //same concept
        exponent >>= 1;                          // remove current power of 2 
                                                            //equivalent to (exponent /= 2)
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,u,a,cnt,ans=1;
    cin>>n;
    for(int x=2;x<50000;x++){
        if(sieve[x]==false){
            primes.push_back(make_pair(x,0));
            u=x+x;
            while(u<50000){
                sieve[u]=true;
                u+=x;
            }
        }
    }
    for(int x=0;x<n;x++){
        cin>>a;
        a++;
        cnt=0;
        for(int y=0;y<primes.size();){
            if(a==1)break;
            if((a%primes[y].first)==0){
                a/=primes[y].first;
                cnt++;
            }else{
                primes[y].second=max(primes[y].second,cnt);
                cnt=0;
                y++;
            }
        }
    }
    for(int x=0;x<primes.size();x++){
        ans*=ipow(primes[x].first,primes[x].second);
        ans%=1000000007;
    }
    ans--;
    if(ans<0)ans+=1000000007;
    cout<<ans;
    return 0;
}