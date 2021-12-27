// ans.cpp 4 Nov 20, 15:49:42 0 0 Judging completed in 3.743s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l,t,d=0,cnt=0;
	cin>>n>>l>>t;
	int arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]-arr[i-1]>t){
			cout<<-1;
			return 0;
		}
	}
	if(l-arr[n-1]>t||arr[0]>t){
		cout<<-1;
		return 0;
	}
	arr[n]=999999;
	for(int i=0;i<n;i++){
		
		if(d+t>=l){
//			cout<<"=case 2 "<<i<<"\n";
			break;
		}else if(arr[i+1]-d<=t&&d+t<l){
//			cout<<"=case 1 "<<i<<"\n";
			continue;
		}
		else{
//			cout<<"=case 3 "<<i<<"\n";
			d=arr[i];
//			cout<<"="<<d<<"\n";
			cnt++;
		}
	}
	cout<<cnt;
}