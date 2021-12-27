// summit.cpp 4 Nov 20, 18:52:44 0 0 Judging completed in 3.629s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool reach(long long k,long long d,long long m){
	long long sum=k;
	while(k/d>0){
		sum+=k/d;
		d*=(d+1);
	}
	if(sum>=m)return true;
	else return false;
}
int main(){
	int m,d;
	cin>>m>>d;
	long long lo=0,hi=m,ans=0;
	while(lo<=hi){
		long long mid=(lo+hi)/2;
		bool satisfy=reach(mid,d,m);
		if(!satisfy){
			lo=mid+1;
		}
		else{
			ans=mid;
			hi=mid-1;
		}
	}
	cout<<ans;
}