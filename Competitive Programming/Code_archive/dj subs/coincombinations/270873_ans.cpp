// ans.cpp 27 Nov 17, 14:58:59 100 0 Judging completed in 7.39s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v;
    int *dp = new int[10005];
    cin >> n >> v;
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        for (int j = x; j <= v; j++){
            dp[j]+=dp[j-x];
            dp[j]%=13371337;
        }
    }
    cout << dp[v] << endl;
}