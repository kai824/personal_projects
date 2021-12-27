// ans.cpp 2 Dec 17, 14:50:59 40 0.05 Judging completed in 8.915s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short int n,k;
    cin>>n;
    short int arr[n];
    for(short int x=0;x<n;x++){cin>>arr[x];}
    cin>>k;
    for(short int x=0;x<n;x++){
        cout<<arr[x]+k<<endl;
    }
    return 0;
}