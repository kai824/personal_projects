// ans.cpp 19 Feb 19, 21:04:16 100 0.88 Judging completed in 4.831s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,u=0;
    cin>>a;
    string b;
    vector<string> d;
    for(int c=0;c<a;c=c+1){
        cin>>b;
        d.push_back(b);
    }
    sort(d.begin(),d.end());
    b="";
    for(int c=0;c<d.size();c=c+1){
        if (c!=0){
            if(d[c]==b){
            }
            else u=u+1;
        }
        b=d[c];
    }
    u=u+1;
    cout<<u;
    return 0;
}