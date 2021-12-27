// ans.cpp 10 Aug 17, 17:01:56 20 0 Judging completed in 3.205s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int nums[10005];//guest numbers...
int arr[10005];//lucky draw numbers...
int main() {
    int n,i,c,a,b,current,ans;
    cin>>n>>i;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        nums[a]=b;
        arr[b]++;
    }
    current=INT_MAX;
    for(int x=1;x<=10000;x++){
        if(arr[x]==0)continue;
        current=min(current,arr[x]);
    }
    ans+=current;
    for(int y=0;y<i-1;y++){
    cin>>c;
    for(int x=0;x<c;x++){
        cin>>a>>b;
        arr[nums[a]]--;
        if(b!=0){
            arr[b]++;
            nums[a]=b;
        }
    }
    current=INT_MAX;
    for(int x=1;x<=10000;x++){
        if(arr[x]==0)continue;
        current=min(current,arr[x]);
    }
    ans+=current;
    }
    cout<<ans;
    return 0;
}