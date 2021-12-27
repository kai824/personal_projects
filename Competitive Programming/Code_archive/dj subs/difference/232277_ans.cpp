// ans.cpp 27 Oct 17, 21:49:29 40 1 Judging completed in 6.536s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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