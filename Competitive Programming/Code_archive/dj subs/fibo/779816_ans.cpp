// ans.cpp 9 Nov 20, 15:18:17 87.5 0 Judging completed in 3.67s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long arr[1000] = {0,1};
long long fib(int num,long long mod){
    if (num == 0){
        return 0;
    }else if (num == 1){
        return 1;
    }else{
        if (arr[num] != 0){
            return arr[num];
        }else{
            arr[num] = (fib(num-1,mod) + fib(num-2,mod))%mod;
            return arr[num];
        }
    }
}
int main() {
    int N;
    long long M,answer; cin >> N >> M;
    answer = fib(N,M) % M;
    cout << answer; 
}