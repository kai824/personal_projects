// ans.cpp 24 Nov 19, 16:39:11 40 0.07 Judging completed in 4.363s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
    if(a.length()==b.length())return a>b;
    return a.length()>b.length();
}
bool cmp2(string a,string b){
    for(int x=0;x<min(a.length(),b.length());x++){
        if(a[x]!=b[x])return a[x]>b[x];
    }
    return a.length()<b.length();
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin>>n>>k;
    string arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n,cmp);
    sort(arr,arr+k,cmp2);
    for(int x=0;x<k;x++){
        cout<<arr[x];
    }
    return 0;
}