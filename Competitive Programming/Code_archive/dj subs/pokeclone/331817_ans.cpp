// ans.cpp 1 Mar 18, 20:16:46 20 0 Judging completed in 4.507s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,lo,hi,mid,ans=1;
    cin>>n;
    int arr[n],arr2[n];
    int lisl[n],lisl2[n];
    vector<int> lis,lis2;
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr2[x]=arr[x];
    }
    lis.push_back(arr[0]);
    arr[0]=1;
    for(int x=1;x<n;x++){
        if(arr[x]>lis[lis.size()-1]){
            lis.push_back(arr[x]);
            continue;
        }
        //binary search
        //find smallest number larger or equal to than arr[x]
        //1 2 4...    4
        //|   |
        lo=0;
        hi=lis.size()-1;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(lis[mid]>=arr[x]){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        lis[lo]=arr[x];
        arr[x]=lis.size();
    }
    
    lis2.push_back(arr2[n-1]);
    arr2[n-1]=1;
    for(int x=n-2;x>=0;x--){
    	if(arr2[x]>lis2[lis.size()-1]){
    		lis2.push_back(arr[x]);
    		continue;
    	}
    	lo=0;
    	hi=lis2.size()-1;
    	while(lo<hi){
            mid=(lo+hi)/2;
            if(lis2[mid]>=arr2[x]){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        lis2[lo]=arr2[x];
        arr2[x]=lis2.size();
    }
    for(int x=0;x<n;x++){
    	ans=max(ans,min(arr[x],arr2[x]));
    }
    cout<<ans+ans-1;
	return 0;
}