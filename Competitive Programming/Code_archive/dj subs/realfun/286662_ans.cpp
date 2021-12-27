// ans.cpp 10 Dec 17, 21:39:30 35 0.19 Judging completed in 3.341s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,xx[200005],yy[200005];
bool masked[200005];

bool fits2(ll size){
    ll maxx=LLONG_MIN,maxy=LLONG_MIN,minx=LLONG_MAX,miny=LLONG_MAX,cnt=0;
    //the corners of the leftovers...
    for(ll x=0;x<n;x++){
        if(masked[x]==1)continue;//can be ignored...
        maxx=max(maxx,xx[x]);
        minx=min(minx,xx[x]);
        maxy=max(maxy,yy[x]);
        miny=min(miny,yy[x]);
        cnt++;
    }
    if(cnt<=2)return true;
    if(maxy-miny<=size && maxx-minx<=size){
        return true;
    }
    bool broke=false;
    for(ll x=0;x<n;x++){
        if(xx[x]-minx<=size && yy[x]-miny<=size)continue;
        if(maxx-xx[x]<=size && maxy-yy[x]<=size)continue;
        
        //if it's running here, the coord cannot fit llo the 2 squares...
        broke=true;
        break;
    }
    if(broke==false)return true;
    broke=false;
    for(ll x=0;x<n;x++){
        if(maxx-xx[x]<=size && yy[x]-miny<=size)continue;
        if(xx[x]-minx<=size && maxy-yy[x]<=size)continue;
        
        //if it's running here, the coord cannot fit llo the 2 squares...
        broke=true;
        break;
    }
    if(broke==false)return true;
    return false;
}

bool fits3(ll size,ll maxx,ll maxy,ll minx,ll miny){//whether 3 squares of size size will cover everything...
    //top left
    memset(masked,0,sizeof(masked));
    for(ll x=0;x<n;x++){
        if(xx[x]-minx<=size && yy[x]-miny<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    memset(masked,0,sizeof(masked));
    //top right
    for(ll x=0;x<n;x++){
        if(xx[x]-minx<=size && maxy-yy[x]<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    memset(masked,0,sizeof(masked));
    //bottom left
    for(ll x=0;x<n;x++){
        if(maxx-xx[x]<=size && yy[x]-miny<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    memset(masked,0,sizeof(masked));
    //bottom right
    for(ll x=0;x<n;x++){
        if(maxx-xx[x]<=size && maxy-yy[x]<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll maxx=LLONG_MIN,maxy=LLONG_MIN,minx=LLONG_MAX,miny=LLONG_MAX;
    cin>>n;
    for(ll x=0;x<n;x++){
        cin>>xx[x]>>yy[x];
        maxx=max(maxx,xx[x]);
        minx=min(minx,xx[x]);
        maxy=max(maxy,yy[x]);
        miny=min(miny,yy[x]);
    }
    ll lo=1,hi=2000000000,mid;
    while(hi-lo>1){
        mid=lo+( (hi-lo)/2 );
        if(fits3(mid,maxx,maxy,minx,miny)){
            hi=mid;
        }else{
            lo=mid;
        }
    }
    if(fits3(lo,maxx,maxy,minx,miny))cout<<lo;
    else cout<<hi;
    return 0;
}