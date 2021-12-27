// ans.cpp 17 Dec 18, 18:28:45 100 0.01 Judging completed in 2.223s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=0;
    cin>>n;
    int arr[n],front_min[n],back_min[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    front_min[0]=arr[0];
    for(int x=1;x<n;x++){
        front_min[x]=min(front_min[x-1],arr[x]);
    }
    back_min[n-1]=arr[n-1];
    for(int x=n-2;x>=0;x--){
        back_min[x]=min(back_min[x+1],arr[x]);
    }
    for(int x=1;x+1<n;x++){
        if(arr[x]-front_min[x-1]<=0 || arr[x]-back_min[x+1]<=0){
            continue;//no possibility of a legit course
        }
        ans=max(ans,(arr[x]-front_min[x-1])+(arr[x]-back_min[x+1]) );
    }
    cout<<ans;
    return 0;
}