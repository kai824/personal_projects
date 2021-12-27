// ans.cpp 24 Dec 17, 18:57:06 0 0 Judging completed in 5.695s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[30000003],current;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,a,b;
    cin>>n>>q;
    for(int x=0;x<q;x++){
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }
    for(int x=0;x<n;x++){
        cout<<(current%2);
    }
    return 0;
}