// ans.cpp 22 Nov 19, 12:07:54 0 0.32 Judging completed in 4.358s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int sums[5005];
bool broke;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,c,cur_start=0,ans=INT_MAX;
    cin>>n>>c;
    string arr[5005];
    for(int x=0;x<c;x++){
        cin>>arr[x];
        for(int i=0;i<n;i++){
            if(arr[x][i]=='1'){
                sums[i]++;
            }
        }
        while(cur_start<x){
            broke=false;
            for(int i=0;i<n;i++){
                if(arr[cur_start][i]=='1' && sums[i]==1){
                    broke=true;
                    break;
                }
            }
            if(broke)break;
            for(int i=0;i<n;i++){
                if(arr[cur_start][i]=='1'){
                    sums[i]--;
                }
            }
            cur_start++;
        }
        broke=false;
        for(int i=0;i<n;i++){
            if(sums[i]==0){
                broke=true;break;
            }
        }
        if(broke)continue;
        ans=min(ans,x-cur_start);
    }
    if(ans==INT_MAX){
        while(true){};
    }
    cout<<ans;
    return 0;
}