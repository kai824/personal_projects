// ans.cpp 27 Nov 17, 14:55:59 100 0.14 Judging completed in 3.646s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,lo,hi,mid;
    cin>>n;
    int arr[n];
    vector<int> lis;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    lis.push_back(arr[0]);
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
    }
    cout<<lis.size();
    return 0;
}