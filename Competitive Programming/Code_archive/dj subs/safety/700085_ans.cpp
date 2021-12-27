// ans.cpp 14 Feb 20, 21:06:30 100 0.29 Judging completed in 3.97s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/

typedef long long ll;

ll first_val=0,first_grad,prevv;
ll lazy1,lazy2;
multiset<ll>ss1,ss2;//ss1 for the front, ss2 for the back
//each point represents an increment in the gradient by 1...

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	for(int x=n-1;x>=0;x--){
		if(x==n-1){
			ss1.insert(arr[x]);
			ss2.insert(arr[x]);
			first_grad=-1;//gradient before the first increment...
			continue;
		}
		lazy1-=k;
		lazy2+=k;//move them apart by k...

		if(arr[x]<*ss1.begin()+lazy1){//new thing...
			first_val+=abs(first_grad* (*ss1.begin()+lazy1-arr[x]) );
		}else{
			first_val+=abs(*ss1.begin()+lazy1-arr[x]);//see the difference...
		}
		first_grad-=1;
		if(ss2.size()==0 || arr[x]< *ss2.begin()+lazy2){
			ss1.insert(arr[x]-lazy1);
			ss1.insert(arr[x]-lazy1);
		}else{
			ss2.insert(arr[x]-lazy2);
			ss2.insert(arr[x]-lazy2);
		}
		while(ss1.size()>ss2.size()){
			ss2.insert(*ss1.rbegin()+lazy1-lazy2);
			ss1.erase(--ss1.end());
		}
		while(ss2.size()>ss1.size()){
			ss1.insert(*ss2.begin()+lazy2-lazy1);
			ss2.erase(ss2.begin());
		}
	}
	prevv=*ss1.begin();
	for(auto it=ss1.begin();it!=ss1.end();it++){
		first_val+=first_grad*abs(*it-prevv);
		first_grad++;
		prevv=*it;
	}
	cout<<first_val<<'\n';
	return 0;
}