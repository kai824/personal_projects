// ans.cpp 2 Dec 17, 14:51:41 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;short arr[n];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short n,k;
    cin>>n;
    
    for(short x=0;x<n;x++){cin>>arr[x];}
    cin>>k;
    for(short x=0;x<n;x++){
        cout<<arr[x]+k<<endl;
    }
    return 0;
}