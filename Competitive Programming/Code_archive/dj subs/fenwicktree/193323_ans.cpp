// ans.cpp 18 Feb 17, 23:27:37 0 0.61 Judging completed in 6.088s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
int ft[100005]={0},n,m,a,b,c,ft2[100005]={0};
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0,p2=p;
	for(; p; p -= ls(p))sum+=ft[p];
	sum*=p2;
	for(;p2;p2-=ls(p2))sum-=ft2[p2];
	return sum;
}
void update(int p, int v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
void update2(int p, int v) {
	for(; p <= n; p += ls(p)){
		ft2[p] += v;//n is the number of elements
	}
}
int main() {
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>a;
        update(x,a);
        update(x+1,-a);
        update2(x,a*(x-1));
        update2(x+1,-a*x);
    }
    cin>>m;
    for(int x=0;x<m;x++){
        cin>>a;
        if(a==0){
            cin>>a>>b;
            cout<<query(b+1)-query(a)<<'\n';
        }else{
            cin>>a>>b>>c;
            update(a+1,c);
            update(b+2,-c);
            update2(a+1,c*a);
            update2(b+2,-c*b+1);
        }
    }
    return 0;
}