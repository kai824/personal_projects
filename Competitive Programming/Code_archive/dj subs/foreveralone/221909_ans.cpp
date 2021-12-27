// ans.cpp 9 Oct 17, 22:25:59 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool test[INT_MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b,ans;
    cin>>n>>m;
    ans=n;
    for(int x=0;x<m;x++){
        cin>>a>>b;
        if(a==b)continue;
        if(test[a]==false){
            test[a]=true;
            ans--;
        }
        if(test[b]==false){
            test[b]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}