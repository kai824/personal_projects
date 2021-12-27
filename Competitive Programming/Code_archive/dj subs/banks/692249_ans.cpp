// ans.cpp 1 Feb 20, 13:20:04 9 1 Judging completed in 5.155s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

bool broke;
int n,m;
int original[2005];
int weights[2005];
pair<int,int> arr[2005];

bool brute_force(int layer){
	if(layer>m){
		broke=false;
		for(int x=1;x<=n;x++){
			if(original[x]!=0){
				broke=true;
				break;
			}
		}
		if(broke==false)return true;//it worked!!!
		return false;
	}
	for(weights[layer]=1;weights[layer]<=n;weights[layer]++){
		original[arr[layer].first]+=weights[layer];
		original[arr[layer].second]-=weights[layer];
		if(brute_force(layer+1))return true;
		original[arr[layer].first]-=weights[layer];
		original[arr[layer].second]+=weights[layer];
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int x=1;x<=m;x++){
		cin>>arr[x].first>>arr[x].second;
	}
	if(brute_force(1)==false)cout<<"NO";
	else{
		cout<<"YES\n";
		for(int x=1;x<=m;x++){
			cout<<weights[x];
			if(x+1<=m)cout<<' ';
		}
	}
	return 0;
}