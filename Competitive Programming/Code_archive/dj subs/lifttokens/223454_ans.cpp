// ans.cpp 18 Oct 17, 16:05:20 10 0 Judging completed in 5.13s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
int coins[9]={1,5,10,50,100,500,1000,5000,10000};//and 17
void g(int a,int b,int c){
    //amount, next coin to use, amt of coins used...
    for(int x=b;x>=0;x--){
        c+=(a/coins[x]);
        a%=coins[x];
    }
    ans=min(ans,c);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,u=0;
    cin>>n;
    for(int x=8;x>=0;x--){
        g(n,x,u);
        g(n%17,x,u+(n/17));
        u+=(n/coins[x]);
        n%=coins[x];
    }
    cout<<ans;
    return 0;
}