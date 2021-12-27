// ans.cpp 23 Oct 17, 22:13:33 0 0 Judging completed in 5.386s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ps[5005][5005];//the normal one...
ll ts[5005][5005];//the diagonal one...
ll ps_query(ll xx,ll yy,ll xx2,ll yy2){
	return(ps[xx2][yy2]-ps[xx2][yy-1]+ps[xx-1][yy-1]-ps[xx-1][yy2]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,a,sum,current,maxi=INT_MIN;
    cin>>n>>k;
    for(ll x=1;x<=n;x++){
    	current=0;
        for(ll y=1;y<=n;y++){
            cin>>a;
            current+=a;
            ps[x][y]=ps[x-1][y]+current;
            ts[x][y]=ts[x-1][y+1]+a;
        }
    }
    for(ll x=1;x<=n-k+1;x++){
        sum=0;
        for(ll y=0;y<k;y++){
            sum+=(ts[y+x][1]-ts[x-1][y+2]);
        }
        for(ll y=1;y<=n-k+1;y++){
        	maxi=max(maxi,sum);
        	sum-=ps_query(x,y,x+k-1,y);
        	sum+=ts[x+k-1][y+1]-ts[x-1][y+k+1];
        }
    }
    cout<<maxi;
    return 0;
}