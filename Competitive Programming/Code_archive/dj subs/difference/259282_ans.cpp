// ans.cpp 17 Nov 17, 11:33:10 0 0.85 Judging completed in 7.45s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,lo,hi,mid,ans=0,s,e;
    cin>>n>>k;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        lo=x+1;hi=n-1;
        while(lo<hi){//lower_bound
            mid=lo+(hi-lo)/2;
            if(arr[mid]<arr[x]+k){
                lo=mid+1;
            }else{//arr[mid]>=arr[x]
                hi=mid;
            }
            if(lo==x)lo++;
            if(hi==x)hi--;
        }
        s=lo;
        lo=x+1;hi=n-1;
        while(lo<hi){//upper_bound
            //find the largest occurence of arr[x]+k
            mid=hi+lo;
            mid-=(hi+lo)/2;
            if(arr[mid]<=arr[x]+k){
                lo=mid;
            }else{//arr[mid]>arr[x]+k;
                hi=mid-1;
            }
        }
        e=lo;
        ans+=(e-s)+1;
    }
    cout<<ans;
    return 0;
}