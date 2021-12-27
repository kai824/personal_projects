// ans.cpp 18 Dec 19, 15:05:32 0 0.01 Judging completed in 3.87s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	long long arr[n];
	bool ended=false,started=false;
	char c='+';
	long long sum=0;
	vector<long long> v;
	for(int x=0;x<n;x++){
		if(x>0)cin>>c;
		cin>>arr[x];
		if(c=='-')arr[x]=-arr[x];
		if(ended){
			sum+=abs(arr[x]);
			continue;
		}
		if(v.size()>0){
			if(v.back()>0 && arr[x]>0){
				v[v.size()-1]+=arr[x];
			}else if(v.back()<0 && arr[x]<0){
				ended=true;
				sum+=abs(arr[x]);
			}else{
				v.push_back(arr[x]);
			}
		}else v.push_back(arr[x]);
	}
	for(int x=0;x<v.size();x++){
	    if(x>0 && (v[x]/abs(v[x]))*v[x-1]>0){
	        while(true){};
	    }
		sum+=v[x];
		if(v[x]<0){
			if(started==false)started=true;
			else{
				if(-v[x]-v[x-1]>0){
					sum+=2*(-v[x]-v[x-1]);
				}
			}
		}
	}
	cout<<sum;
	return 0;
}