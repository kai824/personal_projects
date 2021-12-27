// ans.cpp 13 Jul 19, 21:11:46 100 0.02 Judging completed in 4.33s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long arr[1005][2005];//n, -k to k
//stores the max amt of value you can have
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    char a;long long b,c,n,k,maxi=0;
    cin>>n>>k;
	for(int x=0;x<2005;x++){
		arr[0][x]=LLONG_MIN;
	}arr[0][1000]=0;
    for(int x=1;x<=n;x++){
        cin>>a>>b>>c;
		for(int y=-k;y<=k;y++){
			arr[x][y+1000]=arr[x-1][y+1000];//if you dont take card
		}
        for(int y=-k;y<=k;y++){
			if(arr[x-1][y+1000]==LLONG_MIN)continue;
			//not valid in the first place
            if(a=='+' && -k<=y+b && y+b<=k){
                arr[x][y+b+1000]=max(arr[x][y+b+1000],arr[x-1][y +1000]+c);
            }else if(a=='-' && -k<=y-b && y-b<=k){
                arr[x][y-b+1000]=max(arr[x][y-b+1000],arr[x-1][y +1000]+c);
            }else if(a=='*' && -k<=y*b && y*b<=k){
                arr[x][(y*b)+1000]=max(arr[x][(y*b)+1000],arr[x-1][y +1000]+c);
            }
        }
		if(x==n){
			for(int y=-k;y<=k;y++){
				maxi=max(maxi,arr[x][y+1000]);
			}
		}
    }
    cout<<maxi;
    return 0;
}