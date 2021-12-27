// ans.cpp 24 Nov 18, 14:39:54 100 0.19 Judging completed in 2.41s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline double divide(ll a,ll b){
	double aa=a,bb=b;
	return aa/bb;
}

//convex hull...
vector<pair<double,pair<double,ll> > >lines;
inline void add_line(double m, ll c){//gradient, y-intercept, assumes increasing gradient
	while(lines.size()>=2){
		//intersect(new, third last)
		if(divide(c-lines[lines.size()-2].second.second,lines[lines.size()-2].second.first-m)<lines.back().first){
			lines.pop_back();//will be irrelevant
		}else break;
	}
	if(lines.size()==0)lines.push_back(make_pair(LLONG_MIN,make_pair(m,c)));
	else lines.push_back(make_pair(divide(c-lines.back().second.second, lines.back().second.first-m),make_pair(m,c)));
}
inline ll query(ll x){//x-coordinate, uses max_point
	ll mid,lo=0,hi=lines.size()-1;
	while(lo<hi){//find highest number less than x...
		mid=hi-(hi-lo)/2;
		if(lines[mid].first<=x)lo=mid;
		else hi=mid-1;
	}
	return lo;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,c,n,constant,tmp;
	cin>>n>>a>>b>>c;
	ll arr[n+1],ps[n+1],dp[n+1];
	//x-coordinate of intersection with prev line, then the gradient, then the y-intercept
	ps[0]=0;dp[0]=0;
	for(int x=1;x<=n;x++){
		cin>>arr[x];
	}
	for(int x=1;x<=n;x++){
		ps[x]=ps[x-1]+arr[x];
	}
	add_line(0,0);
	for(int x=1;x<=n;x++){
		constant=(a*ps[x]*ps[x])+(b*ps[x])+c;
		if(x==1){
			dp[x]=constant;
			add_line( -2*a*ps[x],dp[x]+(a*ps[x]*ps[x])-(b*ps[x]) );
		}else{
			tmp=query(ps[x]);
			//cout<<x<<' '<<tmp<<' '<<lines[tmp].second.first<<' '<<lines[tmp].second.second<<' '<<ps[x]<<' ';
			dp[x]=lines[tmp].second.first*ps[x] +lines[tmp].second.second;
			dp[x]+=constant;
			//cout<<dp[x]<<'\n';
			add_line( -2*a*ps[x],dp[x]+(a*ps[x]*ps[x])-(b*ps[x]) );
		}
	}
	cout<<dp[n];
	return 0;
}