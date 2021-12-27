// ans.cpp 26 Feb 17, 17:40:15 0 0 Judging completed in 7.022s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,w;
    cin>>n>>w;
    pair<int,int> ws[n+1];
    int ks[w]={0};
    for(int x=1;x<=n;x++){
        cin>>ws[x].first>>ws[x].second;
        for(int y=0;y<w;y++){
            if(y!=0)ks[y]=max(ks[y-1],ks[y]);
            if(y+1-ws[x].first>=0)ks[y]=max(ks[y],ks[y-ws[x].first]+ws[x].second);
        }
    }
    cout<<ks[w-1];
    return 0;
}