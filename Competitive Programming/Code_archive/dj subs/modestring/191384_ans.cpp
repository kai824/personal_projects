// ans.cpp 13 Feb 17, 13:04:38 100 0 Judging completed in 2.322s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a,c=0,ans=0;
    vector<int>b;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>a;
        b.push_back(a);
    }sort(b.begin(),b.end());
    a=10000;//now used as prev
    for(int x=0;x<n;x++){
        if(a==b[x]){
            c++;
        }else{
            c=1;
        }
        a=b[x];
        ans=max(ans,c);
    }
    cout<<min(ans,m);
    return 0;
}