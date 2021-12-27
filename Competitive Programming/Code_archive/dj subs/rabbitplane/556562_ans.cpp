// ans.cpp 11 Sep 19, 23:18:58 100 0.06 Judging completed in 14.356s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100000],n,d;
inline bool valid(ll dan){//danger value
	ll left=d;//number of doors still available to place...
	ll nex_door=LLONG_MAX;//next door must that must be placed;
	ll last_door=-1e15;
	for(int x=0;x<n;x++){
		if((x-last_door)>(dan/s[x]))//cannot use last door
		nex_door=min(nex_door,(dan/s[x]) + x);
		if(nex_door==x){
			nex_door=LLONG_MAX;
			last_door=x;
			left--;
			if(left<0)return false;
		}
	}
	if(nex_door!=LLONG_MAX)left--;
	if(left<0)return false;
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	ll maxi=0;//seats, doors
	cin>>n>>d;
	for(int x=0;x<n;x++){
		cin>>s[x];
		maxi=max(maxi,s[x]);
	}
	ll lo=0,hi=maxi*n,mid;
	//binary search the answer
	while(lo<hi){
		mid=lo+(hi-lo)/2;//round up the average
		if(valid(mid)){
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
	cout<<lo;
    return 0;
}