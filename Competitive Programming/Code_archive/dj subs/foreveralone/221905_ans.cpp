// ans.cpp 9 Oct 17, 22:23:52 0 0 Judging completed in 6.345s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool test[1000000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,ans;
    cin>>n>>m;ans=n;
    for(int x=0;x<m;x++){
        cin>>a>>b;
        if(a==b)continue;
        if(test[a]==0){
            test[a]=1;
            ans--;
        }
        if(test[b]==0){
            test[b]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}