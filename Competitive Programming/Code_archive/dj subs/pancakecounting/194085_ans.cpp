// ans.cpp 24 Feb 17, 12:13:57 40 0 Judging completed in 6.276s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){cin>>arr[x];}
    cin>>k;
    for(int x=0;x<n;x++){
        cout<<arr[x]+k<<endl;
    }
    return 0;
}