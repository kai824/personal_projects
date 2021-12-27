// ans.cpp 3 Mar 19, 18:19:05 100 0.19 Judging completed in 4.466s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int longest_path[100005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,e,a,b,c,ans=1;
    cin>>n>>e;
    pair<int,pair<int,int> > edgel[e];//edge list
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        edgel[x]=make_pair(c,make_pair(b,a));
    }
    sort(edgel,edgel+e);
	for(int x=0;x<100005;x++){
		longest_path[x]=0;
	}
    for(int x=0;x<e;x++){
		a=longest_path[edgel[x].second.first];
		b=longest_path[edgel[x].second.second];
        longest_path[edgel[x].second.second]=max(b,a+1);
        longest_path[edgel[x].second.first]=max(b+1,a);
        ans=max(ans,longest_path[edgel[x].second.second]);
        ans=max(ans,longest_path[edgel[x].second.first]);
    }
    cout<<ans;
    return 0;
}