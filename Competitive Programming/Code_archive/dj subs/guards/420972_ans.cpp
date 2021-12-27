// ans.cpp 24 Nov 18, 15:39:24 0 2 Judging completed in 4.35s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,g,a;
	cin>>n>>g;
	int arr[g+1][n+1];
	int ps[n+1];
	ps[0]=0;
	for(int x=1;x<=n;x++){
		cin>>a;
		ps[x]=ps[x-1]+a;
	}
	for(int x=1;x<=n;x++){//when only 1 guard used...
		arr[1][x]=x*ps[x];
	}
	for(int x=2;x<=g;x++){
		for(int y=1;y<=n;y++){
			arr[x][y]=INT_MAX;
			for(int z=x-1;z<y;z++){
				arr[x][y]=min(arr[x][y],arr[x-1][z]+((ps[y]-ps[z])*(y-z)));
			}
		}
	}
	cout<<arr[g][n];
	return 0;
}