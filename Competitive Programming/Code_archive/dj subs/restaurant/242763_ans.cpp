// ans.cpp 5 Nov 17, 21:53:53 100 0.04 Judging completed in 4.264s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return(a>b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,s,ans=0;
    cin>>n>>m>>s;
    int mains[m],sides[s];
    for(int x=0;x<m;x++){
        cin>>mains[x];
    }
    for(int x=0;x<s;x++){
        cin>>sides[x];
    }
    sort(mains,mains+m);
    sort(sides,sides+s);
    sort(sides,sides+n,cmp);
    for(int x=0;x<n;x++){
        ans=max(ans,mains[x]+sides[x]);
    }
    cout<<ans;
    return 0;
}