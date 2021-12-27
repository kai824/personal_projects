// ans.cpp 16 Jul 18, 10:51:38 100 0 Judging completed in 2.69s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool sieve[55556];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,current=0,u;//stores number of primes outputted...
    cin>>n;
    for(int x=2;x<55556;x++){
        if(sieve[x]==0){
            //prime
            if((x%5)==2){
                current++;
                cout<<x;
                if(current==n)return 0;
                cout<<' ';
            }
            u=x+x;
            while(u<55556){
                sieve[u]=1;
                u+=x;
            }
        }
    }
    return 0;
}