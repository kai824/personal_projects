// ans.cpp 28 Jan 18, 21:14:56 100 0.29 Judging completed in 6.246s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    for(int x=0;x<m;x++){
        cin>>a>>b>>c;
        if(a==0){
            int ans=INT_MIN;
            for(int y=b;y<=c;y++){
                ans=max(ans,arr[y]);
            }
            cout<<ans<<'\n';
        }else{
            arr[b]=c;
        }
    }
    return 0;
}