// ans.cpp 18 Oct 17, 16:18:02 40 0 Judging completed in 6.141s on AWS Oregon.
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