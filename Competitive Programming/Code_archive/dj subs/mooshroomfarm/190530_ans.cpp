// ans.cpp 11 Feb 17, 17:19:04 0 0 Judging completed in 11.726s on AWS Ireland.
//submitted to save my 2d fenwick tree(masterpiece)
#include<bits/stdc++.h>
using namespace std;
int ft[100][100],n;
int ls(int x){
	return(x&(-x));
}
int hquery(int a,int p){//horizontal row a, first p elements.
	int sum=0;
	for(;p;p-=ls(p))sum+=ft[a][p];
	return sum;
}
int query(int p, int a){
	int sum=0;
	for(;p;p-=ls(p))sum+=hquery(p,a);
	return sum;
}
void hupdate(int a,int b,int c){//add c to row a element b
	for(;b<=n;b+=ls(b)){
		ft[a][b]+=c;
	}
}
void update(int p,int a,int v){//adds v to tree[p][a]
	for(;p<=n;p+=ls(p)){
		//ft[p]+=v;
		hupdate(p,a,v);
	}
}
int main(){
	n=5;
	update(2,2,3);
	update(3,3,4);
	update(4,4,5);
	cout<<query(5,5)<<endl<<query(4,4)<<endl<<query(3,4);
	return 0;
}