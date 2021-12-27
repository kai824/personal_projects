#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define mp make_pair

vector<pair<int,int> > v;//charging time, j

int dp[1000005];
//dp[i]=min(dp[j]+(n-ending index)*A[i])... convex hull?

//vector<pair<int,int> > lines;
vector<pair<double,pii> > lines;//starting x, m,c

inline double intersect(pii a,pii b){
	return double(a.second-b.second)/double(b.first-a.first);
}

void add_line(int m,int c){//decreasing m...
	if(lines.size()==0){
		lines.emplace_back(-1,mp(m,c) );
		return;
	}
	while(lines.size()>1){
		if(intersect(mp(m,c),lines[lines.size()-2].second)<=lines.back().first){
			lines.pop_back();
		}else break;
	}
	lines.emplace_back(intersect(lines.back().second,mp(m,c) ),mp(m,c) );
	/*for(int i=0;i<lines.size();i++){
		cout<<lines[i].first<<' '<<lines[i].second.first<<' '<<lines[i].second.second<<'\n';
	}
	cout<<"\n\n";*/
}

int query(int x){
	int lo=0,hi=lines.size()-1,mid;
	while(lo<hi){
		mid=hi-((hi-lo)/2);
		if(lines[mid].first>x){
			hi=mid-1;
		}else lo=mid;
	}
	return lines[lo].second.first*x + lines[lo].second.second;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,a,cur_max=-1;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>a;
		if(a>cur_max){
			v.emplace_back(a,x);
			cur_max=a;
		}
	}
	add_line(n,0);//wholesale...
	dp[0]=n*v[0].first;
	if(v.size()>0){
		add_line(n-1-(v[1].second-1),dp[0]);//m, c
		for(int i=1;i<v.size();i++){
			dp[i]=query(v[i].first);//A[i]
			if(i+1<v.size())add_line(n-(v[i+1].second-1)-1,dp[i]);
		}
	}
	cout<<dp[v.size()-1];
	return 0;
}
