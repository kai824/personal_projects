// ans.cpp 22 Jan 17, 19:26:19 100 0 Judging completed in 4.385s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(abs(a-b)+abs(a-c),b+c);
    return 0;
}