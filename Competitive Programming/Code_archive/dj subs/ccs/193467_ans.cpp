// ans.cpp 19 Feb 17, 18:11:23 59 0.33 Judging completed in 3.718s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[300005],n,m,b,c;//on the ft, zero means awake
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(int p, int v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
int main() {
	bool asleep[300005];//false is awake...
    string a;
    cin>>n>>m;
    for(int x=0;x<m;x++){
        cin>>a;
        if(a=="TRANSMIT"){
            cin>>b>>c;
            if(query(c+1)-query(b)==0)cout<<"YES\n";
            else cout<<"NO\n";
        }else if(a=="SLEEP"){
            cin>>b;
            if(!asleep[b+1]){
            asleep[b+1]=true;
            update(b+1,1);
            }
        }else{
            cin>>b;
            if(asleep[b+1]){
            asleep[b+1]=false;
            update(b+1,-1);
            }
        }
    }
    return 0;
}