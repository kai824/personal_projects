// ans.cpp 11 Feb 17, 18:05:46 0 0.01 Judging completed in 5.124s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
int ft[55][105],ft2[55][105],n1,n2;//n1 is vertical,n2 is horizontal
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
	for(;b<=n2;b+=ls(b)){
		ft[a][b]+=c;
	}
}
void update(int p,int a,int v){//adds v to tree[p][a]
	for(;p<=n1;p+=ls(p)){
		//ft[p]+=v;
		hupdate(p,a,v);
	}
}
int hquery2(int a,int p){//horizontal row a, first p elements.
	int sum=0;
	for(;p;p-=ls(p))sum+=ft2[a][p];
	return sum;
}
int query2(int p, int a){
	int sum=0;
	for(;p;p-=ls(p))sum+=hquery2(p,a);
	return sum;
}
void hupdate2(int a,int b,int c){//add c to row a element b
	for(;b<=n2;b+=ls(b)){
		ft2[a][b]+=c;
	}
}
void update2(int p,int a,int v){//adds v to tree[p][a]
	for(;p<=n1;p+=ls(p)){
		//ft[p]+=v;
		hupdate2(p,a,v);
	}
}
int main(){
    ft[2045748957][190957]=1;
	return 0;
}