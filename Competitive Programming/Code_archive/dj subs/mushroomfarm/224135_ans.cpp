// ans.cpp 19 Oct 17, 15:36:30 100 0.77 Judging completed in 5.724s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ps[2005][2005],current,ans;//r,c
//      ans counts the number of solutions we already have
ll query(ll xx, ll yy, ll xx2, ll yy2){
	return(ps[xx2][yy2]+ps[xx-1][yy-1]-ps[xx2][yy-1]-ps[xx-1][yy2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll r,c,k,lo,hi,mid;
    cin>>r>>c>>k;
    for(ll x=1;x<=r;x++){
        current=0;
        for(ll y=1;y<=c;y++){
            cin>>ps[x][y];
            current+=ps[x][y];
            ps[x][y]=ps[x-1][y]+current;
        }
    }
    for(ll x=1;x<=r;x++){
        for(ll y=1;y<=c;y++){
            lo=0;hi=min(r-x,c-y);
            if(query(x,y,x+hi,y+hi)<k)continue;
            while(lo<hi){//find the smallest size that can make it
                mid=(lo+hi)/2;
                if(query(x,y,x+mid,y+mid)<k){
                    lo=mid+1;
                }else{
                    hi=mid;
                }
            }
            ans+=min(r-x,c-y)-lo+1;
        }
    }
    cout<<ans;
    return 0;
}