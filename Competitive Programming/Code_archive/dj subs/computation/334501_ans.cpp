// ans.cpp 8 Mar 18, 19:47:38 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
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
    ll arr[2],sum=arr2[start];
    arr[0]=arr2[start];
    bool bit=1;
    for(int x=1;x<n;x++){
        arr[bit] = ((arr[!bit]% 1000000007) * (arr[!bit]% 1000000007)) % 1000000007; 
        arr[bit] = ((arr[bit]% 1000000007) * ((long long)process(arr[x]))) % 1000000007;
        arr[bit] = (arr[bit]% 1000000007) * ((((arr[!bit]% 1000000007) + (arr[bit]% 1000000007)) * ((arr[bit]% 1000000007) + (arr[!bit]% 1000000007)))% 1000000007); 
        arr[bit] %= 1000000007;
        sum += arr[bit];
        bit=!bit;
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
    long_computation0);
    /*thread t1(long_computation,0);
    thread t2(long_computation,1);
    thread t3(long_computation,2);
    thread t4(long_computation,3);
    thread t5(long_computation,4);
    thread t6(long_computation,5);
    thread t7(long_computation,6);
    thread t8(long_computation,7);
    thread t9(long_computation,8);
    thread t10(long_computation,9);
    thread t11(long_computation,10);
    thread t12(long_computation,11);
    thread t13(long_computation,12);
    thread t14(long_computation,13);
    thread t15(long_computation,14);
    thread t16(long_computation,15);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
    for(int x=0;x<15;x++){
        cout<<ans[x]<<' ';
    }
    cout<<ans[15];*/
    return 0;
}