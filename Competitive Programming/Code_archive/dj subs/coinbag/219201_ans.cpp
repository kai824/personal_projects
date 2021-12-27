// ans.cpp 20 Aug 17, 20:26:53 100 0 Judging completed in 7.621s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int arr[2][505],n,m,w[505],v[505];
bool bit=0;
int main(){
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>w[x]>>v[x];
	}
	for(int x=1;x<=n;x++){
		for(int y=0;y<=m;y++){
			if(y>=w[x]){
				arr[bit][y]=max(max(arr[!bit][y],arr[bit][y-1]),arr[!bit][y-w[x]]+v[x]);
			}else{
				arr[bit][y]=max(arr[!bit][y],arr[bit][y-1]);
			}
		}
		bit=!bit;
	}
	cout<<arr[!bit][m];
	return 0;
}