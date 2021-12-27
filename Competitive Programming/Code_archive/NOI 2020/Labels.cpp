#include<bits/stdc++.h>
using namespace std;

int arr[300005];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,mini=1,maxi=1,d;
	cin>>n;
	arr[0]=1;
	for(int x=1;x<n;++x){
		cin>>d;
		arr[x]=arr[x-1]+d;
		maxi=max(arr[x],maxi);
		mini=min(arr[x],mini);
	}
	if(maxi-mini!=n-1){/*1<=ai<=n*/
		cout<<"-1\n";
	}else{
		for(int x=0;x<n;x++){
			cout<<arr[x]-(mini-1);
			if(x+1<n)cout<<' ';
		}
	}
	return 0;
}
