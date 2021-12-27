// ans.cpp 8 Mar 18, 22:13:38 0 7.36 Judging completed in 11.57s on AWS Oregon.
#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#pragma optimise
typedef long long ll;
ll n,arr2[16],ans[16],id;
inline ll process(ll x) {
    return 64-__builtin_clzll(x)-1;
}
inline ll long_computation(ll start){
    ll arr[2],sum=start;
    arr[0]=start;
    bool bit=1;
    for(int x=1;x<n;x++){
        arr[bit] = ((arr[!bit]% 1000000007) * (arr[!bit]% 1000000007)) % 1000000007; 
        arr[bit] = ((arr[bit]% 1000000007) * ((long long)process(arr[bit]))) % 1000000007;
        arr[bit] = (arr[bit]% 1000000007) * ((((arr[!bit]% 1000000007) + (arr[bit]% 1000000007)) * ((arr[bit]% 1000000007) + (arr[!bit]% 1000000007)))% 1000000007); 
        arr[bit] %= 1000000007;
        sum += arr[bit];
        bit=!bit;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<16;x++){
        cin>>arr2[x];
        //cout<<long_computation(arr[x]);
    }
    int nex=0;
    #pragma omp parallel
    {
        #pragma omp task
        ans[0]=long_computation(arr2[0]);
        #pragma omp task
        ans[1]=long_computation(arr2[1]);
        #pragma omp task
        ans[2]=long_computation(arr2[2]);
        
    }
    for(int x=0;x<16;x++){
        cout<<ans[x];
        if(x+1<16)cout<<' ';
    }
    return 0;
}