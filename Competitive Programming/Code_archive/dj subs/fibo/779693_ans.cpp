// ans.cpp 9 Nov 20, 14:44:03 100 0 Judging completed in 6.737s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int fibo(int x, int y, int m) {
    return (x+y)%m;
}

int main() {
    int n, m, x=0, y=1, z=0;
    cin >> n >> m;
    if(n==0)z=0;
    if(n==1)z=1;
    if (n==2) z=1;
    if (n>2) {
        for (int i=0; i<n-1; i++) {
            z = fibo(x,y,m);
            x = y;
            y = z;
        }
    }
    cout << z;
}