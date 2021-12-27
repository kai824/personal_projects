// ans.cpp 11 Mar 18, 13:43:10 0 17 Judging completed in 22.498s on AWS Oregon.
#include <bits/stdc++.h>
#include <omp.h>
#pragma optimise
using namespace std;
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
    #pragma omp parallel for
    for(int i=0;i<16;i++){
        id = i;
        ans[id]=long_computation(arr2[id]);
    }
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[4]<<' '<<ans[5]<<' '<<ans[6]<<' '<<ans[7]<<' '<<ans[8]<<' '<<ans[9]<<ans[10]<<' '<<ans[11]<<' '<<ans[12]<<' '<<ans[13]<<' '<<ans[14]<<' '<<ans[15];
    return 0;
}