// ans.cpp 26 Dec 17, 15:02:18 100 0.09 Judging completed in 2.822s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ans=0;
    string a;
    set<string>ss;
    cin>>n;
    while(n--){
        cin>>a;
        ss.insert(a);
    }
    cin>>m;
    while(m--){
        cin>>a;
        if(ss.find(a)!=ss.end()){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}