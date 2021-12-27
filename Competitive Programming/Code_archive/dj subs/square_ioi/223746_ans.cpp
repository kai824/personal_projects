// ans.cpp 18 Oct 17, 22:20:50 10 0.1 Judging completed in 5.503s on AWS Oregon.
#include"square.h"
#include<bits/stdc++.h>
using namespace std;
int ps[1005][1005],n,cur,maxi,ans=1;//ans being the count, maxi being the size
int query(int xx, int yy, int xx2, int yy2){
	return(ps[xx2][yy2]+ps[xx-1][yy-1]-ps[xx2][yy-1]-ps[xx-1][yy2]);
}
int findMaxSquare(int m[1000][1000], int N){
    n=N;
    int lo,hi,mid;
    for(int x=1;x<=n;x++){
        cur=0;
        for(int y=1;y<=n;y++){
            cur+=m[x-1][y-1];
            ps[x][y]=cur+ps[x-1][y];
        }
    }
    //declaring prefix sum...
    for(int x=1;x<=n;x++){
    	for(int y=1;y<=n;y++){
    		if(max(x,y)+maxi-1>n)continue;
    		if(query(x,y,x+maxi-1,y+maxi-1)<maxi*maxi)continue;
    		lo=maxi;hi=n-max(x,y);
    		while(lo<hi){
    			mid=(lo+hi)-((lo+hi)/2);
    			if(query(x,y,x+mid-1,y+mid-1)<mid*mid){//cannot make it
    				hi=mid-1;
    			}else{
    				lo=mid;
    			}
    		}
    		if(lo==maxi){
    			ans++;
    		}else if(lo>maxi){
    			ans=1;
    			maxi=lo;
    		}
    	}
    }
    return ans*maxi;
}