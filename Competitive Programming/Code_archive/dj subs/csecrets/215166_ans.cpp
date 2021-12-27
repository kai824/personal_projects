// ans.cpp 17 Jul 17, 20:27:32 30 1 Judging completed in 6.553s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b,ans="";
    int c;
    cin>>a>>b>>c;
    for(int x=0;x<a.length();x+=c){
        for(int y=x;y<x+c;y++){
            ans=ans+" ";
            ans[ans.length()-1]=a[y];
        }
        for(int y=x;y<x+c;y++){
            ans=ans+" ";
            ans[ans.length()-1]=b[y];
        }
    }
    cout<<ans;
    return 0;
}