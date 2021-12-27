// ans.cpp 19 Apr 19, 23:18:45 55 0.22 Judging completed in 5.274s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int arr[300005];
int it[300005];//stores location of sheet i(1...n)
int prop[300005];//stores if it[i-1]<it[i] as it should
int ft[300005];
inline int ls(int x){
	return x & (-x);
}
void update(int p,int v){
	if(v==0)return;
	for(;p<=300002;p+=ls(p)){
		ft[p]+=v;
	}
}
int query(int p){
	int sum=0;
	for(;p;p-=ls(p)){
		sum+=ft[p];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,lo,hi,mid;
	cin>>n>>q;
	for(int x=0;x<n;x++){
		cin>>a;
		arr[x+1]=a;
		it[a]=x+1;
	}
	for(int x=2;x<=n;x++){
		prop[x]=(it[x-1]<it[x]);
		update(x,(it[x-1]<it[x]));
	}
	lo=1;hi=n;//max range of all 1s goes from n to ?(excluded)
	while(lo<hi){
		mid=(lo+hi)/2;
		if(query(n)-query(mid)==n-mid){
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
	cout<<lo-1<<'\n';
	for(int x=0;x<q;x++){
		cin>>a>>b;
		swap(it[arr[a]],it[arr[b]]);
		swap(arr[a],arr[b]);
		if(a>1){
			update(a,(it[a-1]<it[a])-prop[a]);
			prop[a]=(it[a-1]<it[a]);
		}
		update(a+1,(it[a]<it[a+1])-prop[a+1]);
		prop[a+1]=(it[a]<it[a+1]);
		if(b>1){
			update(b,(it[b-1]<it[b])-prop[b]);
			prop[b]=(it[b-1]<it[b]);
		}
		update(b+1,(it[b]<it[b+1])-prop[b+1]);
		prop[b+1]=(it[b]<it[b+1]);
		lo=1;hi=n;//max range of all 1s goes from n to ?(excluded)
		while(lo<hi){
			mid=(lo+hi)/2;
			if(query(n)-query(mid)==n-mid){
				hi=mid;
			}else{
				lo=mid+1;
			}
		}
		cout<<lo-1<<'\n';
		//for(int x=1;x<=n;x++){
		//	cout<<it[x]<<' ';
		//}cout<<'\n';
	}
	return 0;
}