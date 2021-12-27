// ans.cpp 19 Aug 17, 23:11:39 0 0.01 Judging completed in 5.259s on AWS Oregon.
#include <bits/stdc++.h>
#include<thread>
using namespace std;
typedef long long ll;
ll n,ans[16],arr2[16];
ll process(ll x) {
    ll ct = 0;
    ll k = 1;
    while (k <= x) {
        k *= 2; ct++;
    }
    return ct-1;
}
void long_computation(ll start){
    ll arr[n],sum=arr2[start];
    arr[0]=arr2[start];
    for(int x=1;x<n;x++){
        arr[x] = ((arr[(x-1)]% 1000000007) * (arr[(x-1)]% 1000000007)) % 1000000007; 
        arr[x] = ((arr[x]% 1000000007) * ((long long)process(arr[x]))) % 1000000007;
        arr[x] = (arr[x]% 1000000007) * ((((arr[(x-1)]% 1000000007) + (arr[x]% 1000000007)) * ((arr[x]% 1000000007) + (arr[(x-1)]% 1000000007)))% 1000000007); 
        arr[x] %= 1000000007;
        sum += arr[x];
    }
    ans[start]=sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<16;x++){
        cin>>arr2[x];
    }
    long_computation(0);
    long_computation(1);
    long_computation(2);
    long_computation(3);
    long_computation(4);
    long_computation(5);
    long_computation(6);
    long_computation(7);
    long_computation(8);
    long_computation(9);
    long_computation(10);
    long_computation(11);
    long_computation(12);
    long_computation(13);
    long_computation(14);
    long_computation(15);
    for(int x=0;x<15;x++){
        cout<<ans[x]<<' ';
    }
    cout<<ans[15];
    return 0;
}