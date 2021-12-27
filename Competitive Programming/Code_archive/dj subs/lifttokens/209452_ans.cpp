// ans.cpp 5 Jun 17, 21:39:27 10 0 Judging completed in 2.922s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll stuff[10]={10000,5000,1000,500,100,50,17,10,5,1};
ll process(ll n,ll it){
	if(n==0 || it>9)return 0;
	ll cost=0;
	if(it==6){
		return(min((n/stuff[it])+process(n%stuff[it],7),process(n,7)));
	}else{
		cost=n/stuff[it];
		return(cost+process(n%stuff[it],it+1));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    ll n;
    cin>>n;
    cout<<process(n,0);
    return 0;
}