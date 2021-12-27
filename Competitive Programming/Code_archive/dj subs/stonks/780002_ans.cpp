// ans.cpp 9 Nov 20, 16:39:23 100 0.2 Judging completed in 3.915s on AWS Oregon.
#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long max_amt = 0;
    long long stonks[n],price[n],max_price=-1;

    for (int i = 0; i < n; i++) cin >> stonks[i];
    for (int i = 0; i < n; i++) cin >> price[i];

    for (int i = n-1; i > -1; i--){
        max_price=max(max_price,price[i]);
        long long a = stonks[i]*max_price;
        max_amt+=a;
    }
    cout << max_amt;
}