// summit.cpp 4 Nov 20, 18:59:08 0 0 Judging completed in 4.275s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool reach(unsigned long long k,unsigned long long d,unsigned long long m){
	long long sum=k;
	while(k/d>0){
		sum+=k/d;
		d*=(d+1);
	}
	if(sum>=m)return true;
	else return false;
}
int main(){
	unsigned long long  m,d;
	cin>>m>>d;
	unsigned long long lo=1,hi=m,ans=0;
	while(lo<=hi){
		unsigned long long mid=(lo+hi)/2;
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