// ans.cpp 10 Oct 19, 20:51:45 100 0.45 Judging completed in 4.331s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int maxi[10],ans=0,cur;
int bitmask;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    string a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        bitmask=0;cur=0;
        for(int y=0;y<a.length();y++){
            bitmask|=(1<<(a[y]-'0'));
        }
        for(int y=0;y<10;y++){
            if((bitmask&(1<<y))==0)continue;
            cur=max(cur,maxi[y]+1);
        }
        ans=max(ans,cur);
        for(int y=0;y<10;y++){
            if((bitmask&(1<<y))==0)continue;
            maxi[y]=max(cur,maxi[y]);
        }
    }
    cout<<n-(ans);
    return 0;
}