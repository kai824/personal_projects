#include "squarerect.h"
#include "bits/stdc++.h"
using namespace std;

bool am_i_square(int n, int Q) {
  int a=1,b=1,lo,hi,mid,points=0;
  int minx=INT_MAX,maxx=INT_MIN,miny=INT_MAX,maxy=INT_MIN;
  for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			a=10+(x*20);
			b=10+(y*20);
			if(inside_shape(a,b)){
				minx=min(a,minx);
				maxx=max(a,maxx);
				miny=min(b,miny);
				maxy=max(b,maxy);
				points++;
			}
		}
	}
	if(points==0)return false;
	lo=0;hi=20;
	while(lo<hi){
		mid=lo+hi-(lo+hi)/2;//to round up and not down
		if(inside_shape(minx-mid,miny)){
			lo=mid;
		}else hi=mid-1;
	}
	minx-=lo;
  lo=0;
  hi=20;
	while(lo<hi){
		mid=lo+hi-(lo+hi)/2;//to round up and not down
		if(inside_shape(maxx+mid,miny)){
			lo=mid;
		}else hi=mid-1;
	}
	maxx+=lo;
  lo=0;hi=20;
	while(lo<hi){
		mid=lo+hi-(lo+hi)/2;//to round up and not down
		if(inside_shape(minx,miny-mid)){
			lo=mid;
		}else hi=mid-1;
	}
	miny-=lo;lo=0;hi=20;
	while(lo<hi){
		mid=lo+hi-(lo+hi)/2;//to round up and not down
		if(inside_shape(minx,maxy+mid)){
			lo=mid;
		}else hi=mid-1;
	}
	maxy+=lo;
  lo=0;hi=20;
	if(maxx-minx==maxy-miny){
		return true;
	}else return false;
}
