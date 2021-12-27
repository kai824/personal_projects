// ans.cpp 15 Apr 17, 21:12:41 100 0 Judging completed in 4.616s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v[n];
    v[0].push_back(1);
    for(int x=1;x<n;x++){
        v[x].push_back(1);
        for(int y=0;y<x-1;y++){
            v[x].push_back(v[x-1][y]+v[x-1][y+1]);
        }
        v[x].push_back(1);
    }
    cout<<v[n-1][k-1];
    return 0;
}