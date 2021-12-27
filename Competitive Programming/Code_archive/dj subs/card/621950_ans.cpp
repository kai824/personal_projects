// ans.cpp 2 Dec 19, 14:09:55 100 0 Judging completed in 3.402s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,start=0;
    string s;
    cin>>n>>k>>s;
    int arr[n];
    for(int x=0;x<n;x++){
        arr[x]=x;
    }
    for(int x=0;x<s.size();x++){
        if(s[x]=='A'){
            start++;
            start%=n;
        }else if(s[x]=='B'){
            swap(arr[start],arr[(start+1)%n]);
            start++;
            start%=n;
        }
    }
    cout<<arr[(start+k-1)%n]<<' '<<arr[(start+k)%n]<<' '<<arr[(start+k+1)%n];
    return 0;
}