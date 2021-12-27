// ans.cpp 30 Jun 18, 23:13:27 100 0.26 Judging completed in 8.931s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int mm[30000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int x=1;x<=30000000;x++){
        mm[x]=INT_MAX;
    }
    for(int x=0;x<=30000000;x++){
        if(x+1<=30000000)mm[x+1]=min(mm[x]+1,mm[x+1]);
        if(x*2<=30000000)mm[x*2]=min(mm[x]+1,mm[x*2]);
        if(x*3<=30000000)mm[x*3]=min(mm[x]+1,mm[x*3]);
    }
    int n,a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        cout<<mm[a]<<'\n';
    }
    return 0;
}