// ans.cpp 24 Feb 18, 14:44:43 0 0.22 Judging completed in 6.835s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > cnts[1000005];
//second int refers to the index of the last one it will lead to...
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,current,ans=INT_MAX;
	cin>>n>>m;
	for(int x=0;x<n;x++){
		cin>>a;
		cnts[a].push_back(make_pair(x,-1));
	}
	for(int x=0;x<cnts[m].size();x++){
		cnts[m][x].second=cnts[m][x].first;
	}
	
	for(int x=m-1;x>=1;x--){
		current=0;
		for(int y=0;y<cnts[x].size();){
			if(cnts[x][y].first<cnts[x+1][current].first){
				cnts[x][y].second=cnts[x+1][current].second;
				y++;
			}else{
				current++;
				if(current>=cnts[x+1].size()){
					break;
				}
			}
		}
	}
	for(int x=0;x<cnts[1].size();x++){
		ans=min(ans,cnts[1][x].second-cnts[1][x].first+1);
	}
	cout<<ans;
	return 0;
}