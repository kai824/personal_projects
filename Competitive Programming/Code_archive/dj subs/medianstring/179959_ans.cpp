// ans.cpp 11 Jan 17, 16:23:02 100 0 Judging completed in 4.369s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    int b[a];
    for(int x=0;x<a;x++){
        cin>>b[x];
    }
    cout<<b[a/2];
    return 0;
}