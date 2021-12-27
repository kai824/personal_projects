// ans.cpp 22 Nov 19, 12:02:27 0 0.32 Judging completed in 4.52s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int sums[5005];
bool broke;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,c,cur_start=0,ans=INT_MAX;
    cin>>n>>c;
    string arr[c];
    for(int x=0;x<c;x++){
        cin>>arr[x];
        for(int i=0;i<n;i++){
            if(arr[x][i]=='1'){
                sums[i]++;
            }
        }
        while(true){
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
        ans=min(ans,x-cur_start+1);
    }
    cout<<ans-1;
    return 0;
}