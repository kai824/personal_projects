// ans.cpp 24 Feb 18, 17:08:00 0 1.12 Judging completed in 6.832s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>, int> piii;
bool cmp(const piii &a,const piii &b){
	return(a>b);
}
int arr[1000005],max_lis=0,min_length=0;
vector<int> cnts[1000005];
vector<pair<int,int> >condense;
set<piii,bool(*)(const piii& lhs, const piii& rhs)> dp(&cmp);//iterator of last element used, length of lis, first element used
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,cur_it;
	cin>>n>>m;
	for(int x=0;x<n;x++){
		cin>>arr[x];
		condense.push_back(make_pair(arr[x],x));
	}
	sort(condense.begin(),condense.end());
	cur_it=0;
	cnts[0].push_back(arr[condense[0].second]);
	arr[condense[0].second]=0;
	for(int x=1;x<n;x++){
		if(condense[x].first!=condense[x-1].first){
			cur_it++;
		}
		cnts[cur_it].push_back(condense[x].second);
		arr[condense[x].second]=cur_it;
	}
	for(int x=0;x<cnts[0].size();x++){
		dp.insert(make_pair(make_pair(cnts[0][x],1),cnts[0][x]));
	    if(1>max_lis){
	        max_lis=1;
	        min_length=0;
	    }
	}
	set<piii>::iterator it;
	for(int x=1;x<1000000;x++){
		for(int y=0;y<cnts[x].size();y++){
			it=dp.upper_bound(make_pair(make_pair(cnts[x][y],-1),-1));
			if(it==dp.end()){
			    dp.insert(make_pair(make_pair(cnts[x][y],1),cnts[x][y]));
			    if(1>max_lis){
			        max_lis=1;
			        min_length=0;
			    }
			    continue;
			}
			//cout<<cnts[x][y]<<' '<<it->first.first<<' '<<it->first.second+1<<' '<<it->second<<'\n';
			dp.insert(make_pair(make_pair(cnts[x][y],it->first.second+1),it->second));
			if(it->first.second+1>max_lis){
				max_lis=it->first.second +1;
				min_length=cnts[x][y]-it->second;
			}else if(it->first.second+1==max_lis&&cnts[x][y]-it->second<min_length){
				min_length=cnts[x][y]-it->second;
			}
		}
	}
	cout<<min_length+1;
	return 0;
}