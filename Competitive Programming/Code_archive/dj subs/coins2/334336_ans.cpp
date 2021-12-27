// ans.cpp 8 Mar 18, 10:28:35 20 2.97 Judging completed in 12.466s on AWS Oregon.
#include <iostream>
using namespace std;
#pragma optimise
bool ft[30000005];
int s,e,n,q;//a counts the number of starting markers, b counts the number of ending markers...
inline int ls(int x){
	return(x&(-x));
}
inline void rupdate(int a,int b){
	for(;a<=n;a+=ls(a)){
		ft[a]^=1;
	}
	for(;b<=n;b+=ls(b)){
		ft[b]^=1;
	}
}
inline int query(int x){
	int sum=0;
	for(;x;x-=ls(x)){
		sum^=ft[x];
	}
	return sum;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    while(q--){
    	cin>>s>>e;
    	rupdate(s+1,e+2);//change to 1-indexed...
    }
    for(int x=1;x<=n;x++){
    	cout << query(x);
    }
}