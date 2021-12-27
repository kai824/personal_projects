// ans.cpp 10 May 18, 09:28:39 100 0.08 Judging completed in 3.236s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,arr[500001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    arr[n]=INT_MAX;
    sort(arr,arr+n);
    //binary search for answer
    int lo,hi,mid;
    lo=0;
    hi=n;
    while(lo<hi){
    	mid=lo+hi;
        mid-=((lo+hi)/2);
        if(arr[n-mid]>=mid){
            lo=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<lo;
    return 0;
}