// ans.cpp 21 Dec 16, 22:12:17 25 0 Judging completed in 8s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int it=0,ans=0,n,coins[13]={1000000,500000,100000,50000,10000,5000,1000,500,100,50,10,5,1};
    cin>>n;
    while(true){
        if(coins[it]<=n){
            n-=coins[it];
            ans++;
            if(n==0)break;
        }else{
            it++;
        }
    }
    cout<<ans;
    return 0;
}