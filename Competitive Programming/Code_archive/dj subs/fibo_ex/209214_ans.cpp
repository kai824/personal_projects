// ans.cpp 3 Jun 17, 21:20:50 0 0.22 Judging completed in 4.875s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
pair<ull,ull> fibo(ull a,ull m){//returns make_pair(f(a)%m,f(a+1)%m);
	if(a==0){
		return(make_pair(0,1));
	}
	pair<ull,ull> mypair;
	if(a%2==0){
		mypair=fibo(a/2,m);
		mypair.first%=m;
		mypair.second%=m;
		return(make_pair((mypair.first*((2*mypair.second)-mypair.first))%m,((mypair.first*mypair.first)+(mypair.second*mypair.second))%m));
	}else{
		a--;
		mypair=fibo(a/2,m);
		mypair.first%=m;
		mypair.second%=m;
		mypair=make_pair((mypair.first*((2*mypair.second)-mypair.first))%m,((mypair.first*mypair.first)+(mypair.second*mypair.second))%m);
		return(make_pair(mypair.second,(mypair.first+mypair.second)%m));
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ull tc,n,m;
    cin>>tc;
    while(tc--){
    	cin>>n>>m;
    	cout<<(fibo(n-1,m).second)%m<<'\n';
    }
    return 0;
}