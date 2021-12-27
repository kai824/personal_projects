// ans.cpp 17 Nov 17, 15:18:15 30 0 Judging completed in 2.724s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    string ans="";
    cin>>a>>b>>c;
    vector<int> v;
    while(a>0&&b>0){
        d=a%c;
        d+=b%c;
        d%=c;
        v.push_back(d);
        a/=c;
        b/=c;
    }
    while(v.size()>0){
        cout<<v.back();
        v.pop_back();
    }
    return 0;
}