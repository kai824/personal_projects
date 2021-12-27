// summit.cpp 4 Nov 20, 18:53:40 0 0 Compilation failed on AWS Oregon.
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
	while(lo<hi){
	    mid=lo+(hi-lo)/2;
	    if(reach(mid,d,m)){
	        hi=mid;//can reach with this much
	    }else lo=mid+1;
	}
	cout<<ans;
}