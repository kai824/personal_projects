// ans.cpp 21 Dec 16, 22:21:04 100 0 Judging completed in 5.029s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int it,ans=0,n,coins[13]={1000000,500000,100000,50000,10000,5000,1000,500,100,50,10,5,1};
    cin>>n;
    for(int x=0;x<13;x++){
        it=n/coins[x];
        ans+=it;
        n-=it*coins[x];
    }
    cout<<ans;
    return 0;
}