// ans.cpp 18 Feb 17, 22:37:38 0 1 Judging completed in 7.301s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
int ft[100005],n,m,a,b,c;
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
    cin>>n;
    for(int x=1;x<=10;x++){
        cin>>a;
        update(x,a);
    }
    cin>>m;
    for(int x=0;x<m;x++){
        cin>>a;
        if(a==0){
            cin>>a>>b;
            cout<<query(b+1)-query(a)<<'\n';
        }else{
            cin>>a>>b>>c;
            for(int y=a+1;y<=b+1;y++){
                update(y,c);
            }
        }
    }
    return 0;
}