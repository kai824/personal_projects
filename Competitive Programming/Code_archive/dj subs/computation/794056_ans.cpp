// ans.cpp 24 Nov 20, 20:10:48 0 17 Judging completed in 23.271s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
typedef long long ll;
ll n,arr[16];
ll process(ll x) {
    ll ct = 0;
    ll k = 1;
    while (k <= x) {
        k *= 2; ct++;
    }
    return ct-1;
}
ll long_computation(ll start){
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
        cout<<long_computation(arr[x]);
        if(x+1<16)cout<<' ';
    }
    /*future<ll> a1=async(std::launch::async, long_computation,arr[0]);
    future<ll> a2=async(std::launch::async, long_computation,arr[1]);
    future<ll> a3=async(std::launch::async, long_computation,arr[2]);
    future<ll> a4=async(std::launch::async, long_computation,arr[3]);
    future<ll> a5=async(std::launch::async, long_computation,arr[4]);
    future<ll> a6=async(std::launch::async, long_computation,arr[5]);
    future<ll> a7=async(std::launch::async, long_computation,arr[6]);
    future<ll> a8=async(std::launch::async, long_computation,arr[7]);
    future<ll> a9=async(std::launch::async, long_computation,arr[8]);
    future<ll> a10=async(std::launch::async, long_computation,arr[9]);
    future<ll> a11=async(std::launch::async, long_computation,arr[10]);
    future<ll> a12=async(std::launch::async, long_computation,arr[11]);
    future<ll> a13=async(std::launch::async, long_computation,arr[12]);
    future<ll> a14=async(std::launch::async, long_computation,arr[13]);
    future<ll> a15=async(std::launch::async, long_computation,arr[14]);
    future<ll> a16=async(std::launch::async, long_computation,arr[15]);
    cout<<a1.get()<<' '<<a2.get()<<' '<<a3.get()<<' '<<a4.get()<<' '<<a5.get()<<' '<<a6.get()<<' '<<a7.get()<<' '<<a8.get()<<' '<<a9.get()<<' '<<a10.get()<<' '<<a11.get()<<' '<<a12.get()<<' '<<a13.get()<<' '<<a14.get()<<' '<<a15.get()<<' '<<a16.get();
    */return 0;
}