// ans.cpp 16 Nov 20, 16:14:15 100 0 Judging completed in 4.599s on AWS Oregon.
#include <iostream>
#include <iomanip>  //cout << setprecision(2) << num;
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    //io optimization
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //input
    int n,total_w;
    cin >> n;
    cin >> total_w;

    int weights[n];
    int values[n];

    int wi,vi;
    for (int i = 0; i < n; ++i) {
        cin >> wi >> vi;
        weights[i] = wi;
        values[i] = vi;
    }

    int dp[n+1][total_w+1];

    //init
    for (int r = 0; r < total_w + 1; r++) {
        dp[0][r] = 0;
    }
    for (int c = 0; c < n + 1; c++) {
        dp[c][0] = 0;
    }

    //dp
    for (int item = 1; item < n+1; ++item) {
        for (int capacity = 0; capacity < total_w + 1; ++capacity) {
            int max_without = dp[item - 1][capacity];
            int max_with = 0;
            int this_weight = weights[item-1];
            if (capacity >= this_weight) {
                max_with = values[item-1] + dp[item-1][capacity - this_weight];
            }
            dp[item][capacity] = max(max_with, max_without);
            //cout << "setting row col "<< item << " "<<capacity << " to " << dp[item][capacity] << "\n";
        }
    }
    cout << dp[n][total_w];

    return 0;
}