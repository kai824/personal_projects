// ans.cpp 10 Oct 17, 08:14:25 100 3.3 Judging completed in 13.112s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
map<int,bool> test;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,ans;
    cin>>n>>m;
    ans=n;
    for(int x=0;x<m;x++){
        cin>>a>>b;
        if(a==b)continue;
        if(test[a]==0){
            test[a]=true;
            ans--;
        }
        if(test[b]==0){
            test[b]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}