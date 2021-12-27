// ans.cpp 7 Mar 18, 19:26:16 100 0.08 Judging completed in 5.507s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnts[200005],arr[200005],current;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int x=1;x<n+m;x++){
        cin>>a>>b;
        cnts[a]++;
        cnts[b]++;
    }
    for(int x=0;x<=n+m;x++){
        if(cnts[x]==0)continue;
        arr[1]++;
        arr[cnts[x]]--;
    }
    for(int x=1;x<=200000;x++){
        current+=arr[x];
        if(x!=1 && current!=0){
            cout<<x<<' '<<current<<'\n';
        }
    }
    return 0;
}