// ans.cpp 8 Mar 18, 10:27:28 20 2.81 Judging completed in 11.898s on AWS Oregon.
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
	b++;
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
    for(int x=0;x<q;x++){
    	cin>>s>>e;
    	rupdate(s+1,e+1);//change to 1-indexed...
    }
    for(int x=1;x<=n;x++){
    	cout << query(x);
    }
    return 0;
}