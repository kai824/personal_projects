// ans.cpp 10 Dec 17, 21:25:17 35 0.18 Judging completed in 3.389s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,xx[200005],yy[200005];
bool masked[200005];

bool fits2(int size){
    int maxx=INT_MIN,maxy=INT_MIN,minx=INT_MAX,miny=INT_MAX,cnt=0;
    //the corners of the leftovers...
    for(int x=0;x<n;x++){
        if(masked[x]==1)continue;//can be ignored...
        maxx=max(maxx,xx[x]);
        minx=min(minx,xx[x]);
        maxy=max(maxy,yy[x]);
        miny=min(miny,yy[x]);
        cnt++;
    }
    if(cnt<=2)return true;
    if(max(maxy-miny,maxx-minx)<=(2*size) && min(maxy-miny,maxx-minx)<=size){
        return true;
    }
    bool broke=false;
    for(int x=0;x<n;x++){
        if(xx[x]-minx<=size && yy[x]-miny<=size)continue;
        if(maxx-xx[x]<=size && maxy-yy[x]<=size)continue;
        
        //if it's running here, the coord cannot fit into the 2 squares...
        broke=true;
        break;
    }
    if(broke==false)return true;
    broke=false;
    for(int x=0;x<n;x++){
        if(maxx-xx[x]<=size && yy[x]-miny<=size)continue;
        if(xx[x]-minx<=size && maxy-yy[x]<=size)continue;
        
        //if it's running here, the coord cannot fit into the 2 squares...
        broke=true;
        break;
    }
    if(broke==false)return true;
    return false;
}

bool fits3(int size,int maxx,int maxy,int minx,int miny){//whether 3 squares of size size will cover everything...
    //top left
    memset(masked,0,sizeof(masked));
    for(int x=0;x<n;x++){
        if(xx[x]-minx<=size && yy[x]-miny<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    memset(masked,0,sizeof(masked));
    //top right
    for(int x=0;x<n;x++){
        if(xx[x]-minx<=size && maxy-yy[x]<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    memset(masked,0,sizeof(masked));
    //bottom left
    for(int x=0;x<n;x++){
        if(maxx-xx[x]<=size && yy[x]-miny<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    memset(masked,0,sizeof(masked));
    //bottom right
    for(int x=0;x<n;x++){
        if(maxx-xx[x]<=size && maxy-yy[x]<=size)masked[x]=1;
    }
    if(fits2(size))return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int maxx=INT_MIN,maxy=INT_MIN,minx=INT_MAX,miny=INT_MAX;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>xx[x]>>yy[x];
        maxx=max(maxx,xx[x]);
        minx=min(minx,xx[x]);
        maxy=max(maxy,yy[x]);
        miny=min(miny,yy[x]);
    }
    int lo=1,hi=max(maxx-minx,maxy-miny),mid;
    while(lo<hi){
        mid=lo+( (hi-lo)/2 );
        if(fits3(mid,maxx,maxy,minx,miny)){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo;
    return 0;
}