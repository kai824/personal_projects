// ans.cpp 17 Nov 17, 11:59:28 100 0.78 Judging completed in 6.677s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,k,lo,hi,mid,ans=0,s,e,xxx;
    cin>>n>>k;
    ll arr[n+1];
    for(ll x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    arr[n]=arr[n-1]+k+5;
    for(ll x=0;x<n-1;x++){
    	xxx=arr[x];
    	arr[x]=LLONG_MIN;
        lo=x+1;hi=n;
        while(lo<hi){//lower_bound
            mid=lo+(hi-lo)/2;
            if(arr[mid]<xxx+k){
                lo=mid+1;
            }else{//arr[mid]>=arr[x]
                hi=mid;
            }
            if(lo==x)lo++;
            if(hi==x)hi--;
        }
        s=lo;
        lo=x;hi=n;
        while(lo<hi){//upper_bound
            //find the largest occurence of arr[x]+k
            mid=hi+lo;
            mid-=(hi+lo)/2;
            if(arr[mid]<=xxx+k){
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