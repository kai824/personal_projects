// ans.cpp 9 Mar 18, 08:35:07 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#pragma optimise
typedef long long ll;
ll n,arr[16],ans[16];
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
        cin>>arr[x];
        //cout<<long_computation(arr[x]);
    }
    system("-fopenmp");
    #pragma omp parallel num_threads(16)
    {
        int id = omp_get_thread_num();
        ans[id]=long_computation(arr[id]);
    }
    for(int x=0;x<16;x++){
        cout<<ans[x];
        if(x+1<16)cout<<' ';
    }
    return 0;
}