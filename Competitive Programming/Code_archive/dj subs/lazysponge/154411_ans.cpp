// ans.cpp 23 Oct 16, 20:08:47 100 0.01 Judging completed in 4.936s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,e;
    cin>>a>>b;
    int c[a];
    for(int d=1;d<=a;d++){
        cin>>e;
        c[d]=e;
    }
    cout<<c[b];
    return 0;
}