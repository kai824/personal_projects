// ans.cpp 29 Apr 17, 21:05:48 0 0.2 Judging completed in 3.785s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
pair<uint64_t,uint64_t> fibo(uint64_t a,uint64_t m){//returns make_pair(f(a)%m,f(a+1)%m);
	if(a==0){
		return(make_pair(0,1));
	}
	pair<uint64_t,uint64_t> mypair;
	if(a%2==0){
		mypair=fibo(a/2,m);
		return(make_pair((mypair.first*((2*mypair.second)%m-mypair.first))%m,((mypair.first*mypair.first)%m+(mypair.second*mypair.second)%m)%m));
	}else{
		a--;
		mypair=fibo(a/2,m);
		mypair=make_pair((mypair.first*((2*mypair.second)%m-mypair.first))%m,((mypair.first*mypair.first)%m+(mypair.second*mypair.second)%m)%m);
		return(make_pair(mypair.second,mypair.first+mypair.second));
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    uint64_t tc,n,m;
    cin>>tc;
    while(tc--){
    	cin>>n>>m;
    	cout<<fibo(n,m).first<<'\n';
    }
    return 0;
}