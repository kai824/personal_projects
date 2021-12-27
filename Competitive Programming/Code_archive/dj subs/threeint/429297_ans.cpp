// ans.cpp 2 Dec 18, 08:59:50 100 0 Judging completed in 3.444s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k,s,ans=0;
    cin>>k>>s;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            if(x+y<=s && s-(x+y)<=k){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}