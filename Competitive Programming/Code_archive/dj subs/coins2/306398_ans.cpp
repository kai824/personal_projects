// ans.cpp 26 Dec 17, 14:55:11 0 0 Judging completed in 4.546s on AWS Oregon.
#include <iostream>
using namespace std;
int ft[30000005],s,e,n,q;//a counts the number of starting markers, b counts the number of ending markers...
int ls(int x){
	return(x&(-x));
}
void rupdate(int a,int b){
	for(;a<=n;a+=ls(a)){
		ft[a]++;
	}
	b++;
	for(;b<=n;b+=ls(b)){
		ft[b]--;
	}
}
int query(int x){
	int sum=0;
	for(;x;x-=ls(x)){
		sum+=ft[x];
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
    	if((query(x)%2)==0){
    		//coin x flipped an even number of times...
    		cout<<0;
    	}else{
    		//coin x flipped an odd number of times...
    		cout<<1;
    	}
    }
    return 0;
}