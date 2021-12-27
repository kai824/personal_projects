// ans.cpp 23 Dec 19, 21:46:13 100 0.01 Judging completed in 4.212s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int n,m,c;//cows, buses, bus capacity
int arr[100005];

bool can(int timee){
	int prev=arr[0],prev_it=-1,needy=1;
	for(int x=0;x<n;x++){
		if(arr[x]-prev>timee || x-prev_it>c){//x should be on a separate bus...
			needy++;
			prev_it=x-1;
			prev=arr[x];//arrival time of first cow
		}
	}
	if(needy>m)return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>c;
	for(int x=0;x<n;x++){
		cin>>arr[x];//arrival time...
	}
	sort(arr,arr+n);
	int lo,hi,mid;
	lo=0;
	hi=arr[n-1]-arr[0];
	while(lo<hi){
		mid=lo+(hi-lo)/2;
		if(can(mid)){//see if maximal waiting time can be within mid
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
	cout<<lo;
	return 0;
}