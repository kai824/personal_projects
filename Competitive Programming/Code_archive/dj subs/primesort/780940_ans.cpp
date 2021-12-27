// ans.cpp 11 Nov 20, 10:14:41 100 0.33 Judging completed in 7.833s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnt[1000005];
bool marked[1000005];

void dfs(int x){
    for(int i=0;i<cnt[x];i++)cout<<x<<'\n';
    marked[x]=true;
    for(int i=2;x*i<=1000000;i++){
        if(marked[x*i])continue;
        dfs(x*i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        cnt[a]++;
    }
    dfs(1);
    return 0;
}