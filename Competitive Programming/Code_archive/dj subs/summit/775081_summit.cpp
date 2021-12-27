// summit.cpp 4 Nov 20, 18:56:53 20 0 Judging completed in 3.314s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

uint64_t kd(uint64_t k,int d){
    uint64_t to_divide=1,height_climbed=0;
    for(uint64_t a=0;a==a;a=a+1){
        height_climbed += k/to_divide;
        if(k/to_divide<=0) break;
        to_divide=to_divide*(d+a);
    }
    return height_climbed;
}

bool reach(long long k,long long d,long long m){
	return kd(k,d)>=m;
}
int main(){
	int m,d;
	cin>>m>>d;
	long long lo=0,hi=m*d/(d+1),ans=0;
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