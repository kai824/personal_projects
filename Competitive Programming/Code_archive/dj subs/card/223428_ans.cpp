// ans.cpp 18 Oct 17, 15:36:52 100 0 Judging completed in 3.088s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
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