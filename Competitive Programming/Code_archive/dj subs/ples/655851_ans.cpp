// ans.cpp 19 Dec 19, 10:39:17 100 0.02 Judging completed in 4.911s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

vector<int> short_b,short_g,high_b,high_g;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,a,it1,it2,ans=0;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>a;
		if(a<0){
			short_b.push_back(-a);//wtd with sb shorter...
		}else{
			high_b.push_back(a);//wtd with sb taller
		}
	}
	for(int x=0;x<n;x++){
		cin>>a;
		if(a<0){
			short_g.push_back(-a);//wtd with sb shorter...
		}else{
			high_g.push_back(a);//wtd with sb taller
		}
	}
	sort(short_b.begin(),short_b.end(),greater<int>());
	sort(short_g.begin(),short_g.end(),greater<int>());
	sort(high_b.begin(),high_b.end(),greater<int>());
	sort(high_g.begin(),high_g.end(),greater<int>());

	it1=it2=0;
	while(it1<short_b.size() && it2<high_g.size()){
		if(short_b[it1]>high_g[it2]){
			it1++;
			it2++;
			ans++;
		}else{
			it2++;
		}
	}
	it1=it2=0;
	while(it1<short_g.size() && it2<high_b.size()){
		if(short_g[it1]>high_b[it2]){
			it1++;
			it2++;
			ans++;
		}else{
			it2++;
		}
	}
	cout<<ans;
	return 0;
}