// ans.cpp 17 Oct 17, 10:27:52 0 1 Judging completed in 4.064s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2000005];
int main() {
    int n,h,a,b;
    cin>>n>>h;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if(a==0)arr[b%h]--;
        else arr[b%h]++;
        cout<<(arr[b%h]>1)<<'\n';
    }
    return 0;
}