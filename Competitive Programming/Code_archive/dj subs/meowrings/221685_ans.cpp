// ans.cpp 7 Oct 17, 22:05:49 0 0 Judging completed in 4.74s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0,u,n2;
    cin>>n;
    n2=n;
    char sieve[n+1];
    for(int x=0;x<=n;x++){
        sieve[x]='n';//not tested
    }
    for(int x=2;x<n2;x++){
        if(sieve[x]=='n'){//the number is prime...
            u=x;
            while(u<n2){
                sieve[u]='z';
                u+=x;
            }
            while(n%x==0){
              n/=x;
              ans+=x;
            }
        }else{
            continue;
        }
    }
    cout<<ans;
    return 0;
}