// ans.cpp 15 Apr 17, 21:17:47 100 0 Judging completed in 4.307s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a;
    cin>>n;
    int arr[n+5];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[a]=x+1;
    }
    for(int x=1;x<=n;x++){
        cout<<arr[x]<<'\n';
    }
    return 0;
}