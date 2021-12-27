// ans.cpp 18 Feb 17, 22:39:34 57 1 Judging completed in 6.368s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
long long int ft[100005],n,m,a,b,c;
long long int ls(int x){
	return(x & (-x));
}
long long int query(long long int p) {
	long long int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(long long int p,long long int v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
int main() {
    cin>>n;
    for(long long int x=1;x<=n;x++){
        cin>>a;
        update(x,a);
    }
    cin>>m;
    for(long long int x=0;x<m;x++){
        cin>>a;
        if(a==0){
            cin>>a>>b;
            cout<<query(b+1)-query(a)<<'\n';
        }else{
            cin>>a>>b>>c;
            for(long long int y=a+1;y<=b+1;y++){
                update(y,c);
            }
        }
    }
    return 0;
}