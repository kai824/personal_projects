// ans.cpp 12 Dec 16, 21:51:50 0 1 Judging completed in 9.28s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
double t=clock();
int ft[1000003],n=1,a,c,hi;
bool candies[1000003];
short int b;
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	if(p==0)return 0;
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(int p, int v) {
	for(; p <= 1000003; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>a;
	for(int x=0;x<a;x++){
		cin>>b>>c;
		if(b==1){
			if(candies[c]==false){
				n=max(n,c);
				candies[c]=true;
				update(c,1);
			}
		}else if(candies[c]==true){
			candies[c]=false;
			update(c,-1);
		}else{
			continue;
		}
		/*Binary search after updating fenwick tree.*/
		b=0;//b=lo,mid=c
		hi=n;
		for(int y=1;(hi>b && y<=100);y++){
			c=b+(hi-b)/2+1;
			if(query(c)==c)b=c;
			else hi=c-1;
		}
		cout<<b<<endl;
	}
	return 0;
}