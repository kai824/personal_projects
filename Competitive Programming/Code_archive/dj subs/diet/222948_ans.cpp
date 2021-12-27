// ans.cpp 17 Oct 17, 09:06:32 100 0.07 Judging completed in 2.921s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2][45005],n,m,w[505],v[505];
bool bit=0;
int main() {
    int n,m;
    cin>>m>>n;
    for(int x=1;x<=n;x++){
        cin>>w[x];
        v[x]=w[x];
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