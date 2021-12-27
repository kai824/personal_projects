// ans.cpp 24 Feb 17, 12:16:59 40 0 Judging completed in 6.6s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n;
    short int arr[n];
    for(int x=0;x<n;x++){cin>>arr[x];}
    cin>>k;
    for(int x=0;x<n;x++){
        cout<<arr[x]+k<<endl;
    }
    return 0;
}