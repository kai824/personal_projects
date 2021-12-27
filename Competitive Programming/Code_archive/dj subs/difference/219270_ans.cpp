// ans.cpp 21 Aug 17, 21:14:55 40 1 Judging completed in 6.669s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,lo,hi,mid,ans=0;
    cin>>n>>k;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        lo=x+1;hi=n-1;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(arr[mid]<arr[x]+k){
                lo=mid+1;
            }else{//arr[mid]>=arr[x]
                hi=mid;
            }
            if(lo==x)lo++;
            if(hi==x)hi--;
        }
        if(arr[lo]==arr[x]+k){
        	ans++;
        	for(int y=lo+1;y<n;y++){
        		if(arr[y]==arr[lo])ans++;
        		else break;
        	}
        }
    }
    cout<<ans;
    return 0;
}