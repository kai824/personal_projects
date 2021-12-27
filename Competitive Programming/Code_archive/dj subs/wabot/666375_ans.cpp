// ans.cpp 28 Dec 19, 13:56:28 0 0.2 Judging completed in 6.079s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

deque<pair<int,set<int> > > v;//level,complexities...

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,l,c;
	cin>>n;
	ll ans=0;
	pair<ll,ll> arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x].first>>arr[x].second;
	}
	sort(arr,arr+n);
	set<int> ss;ss.insert(arr[0].second);

	v.push_back(make_pair(arr[0].first,ss));
	for(int x=1;x<n;x++){
		if(arr[x].first==arr[x-1].first){
			v.back().second.insert(arr[x].second);
		}else{
			ss.clear();ss.insert(arr[x].second);
			v.push_back(make_pair(arr[x].first,ss));
		}
	}
	while(v.size()>0){
		ss.clear();
		for(auto it=v[0].second.begin();it!=v[0].second.end();it++){
			c=*it;
			it++;
			if(it==v[0].second.end())break;//odd number of stuff
			c+=*it;
			if(v.size()==1 || v[1].first!=v[0].first+1){
				ss.insert(c);//the next level...
			}else v[1].second.insert(c);
			ans+=c;
		}
		if(v.size()==1 || v[1].first!=v[0].first+1){
			v[0].first++;
			v[1].second=ss;
			if(ss.size()==0){
				v.pop_front();
			}
		}
		v.pop_front();
	}
	cout<<ans;
	return 0;
}
/*
5
1 1
1 2
1 3
2 4
2 5
*/