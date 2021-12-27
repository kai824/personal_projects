// ans.cpp 17 Oct 17, 12:10:00 0 0 Judging completed in 8.791s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int v[10005], V, n, dem[10005]; cin >> n >> V;
    for (int i = 0; i < n; ++i) cin >> dem[i];
    fill_n(v, 10005, INT_MAX);
    for (int i = 1, tmp; i <= V; ++i){
        if (!binary_search(dem, dem+n, i)){
            tmp = lower_bound(dem, dem+n, i) - dem;
            int mini = INT_MAX;
            for (int j = 0, a; j < tmp; ++j){
                a = dem[j];
                mini = min(v[i-a], mini);
            }
            if (mini != INT_MAX) v[i] = mini + 1;
        }else{
            v[i] = 1;
        }
    }
    if (v[V] == INT_MAX) cout << -1 << '\n';
    else cout << v[V] << '\n';
}