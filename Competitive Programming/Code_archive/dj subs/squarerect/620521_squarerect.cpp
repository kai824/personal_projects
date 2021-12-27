// squarerect.cpp 2 Dec 19, 11:26:38 0 0 Judging completed in 7.845s on AWS Oregon.
#include "squarerect.h"
#include <bits/stdc++.h>
using namespace std;

bool am_i_square(int n, int q){
    //square is at least 20 by 20...
    int minx,miny,maxx,maxy,top,bottom,l,r;
    int lo,hi,mid,length;
    bool found=false;
    minx=miny=INT_MAX;
    maxx=maxy=INT_MIN;
    for(int x=1;x<=4;x++){
        for(int y=1;y<=4;y++){
            if(inside_shape(x*20,y*20)){
                minx=min(minx,x*20);
                maxx=max(maxx,x*20);
                miny=min(miny,y*20);
                maxy=max(maxy,y*20);
                found=true;
            }
        }
    }
    if(found==false){
        for(int x=1;x<=5;x++){
            for(int y=1;y<=5;y++){
                if(max(x,y)<5)continue;
                if(inside_shape(x*20,y*20)){
                    if(x==5){
                        top=81;bottom=100;
                        lo=0;hi=19;
                        while(lo<hi){
                            mid=lo+(hi-lo)/2;
                            if(inside_shape(x*20,y*20-mid)){
                                lo=mid;
                            }else{
                                hi=mid-1;
                            }
                        }
                        l=y*20-mid;
                        if(inside_shape(x*20,l+19)==true && inside_shape(x*20,l+20)==false){
                            return true;
                        }else{
                            return false;
                        }
                    }else if(y==5){
                        l=81;r=100;
                        lo=0;hi=19;
                        while(lo<hi){
                            mid=lo+(hi-lo)/2;
                            if(inside_shape(x*20-mid,y*20)){
                                lo=mid;
                            }else{
                                hi=mid-1;
                            }
                        }
                        top=y*20-mid;
                        if(inside_shape(top+19,y*20)==true && inside_shape(top+20,y*20)==false){
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
    }else{
        lo=0;hi=19;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(inside_shape(minx-mid,miny)){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        top=minx-lo;
        lo=0;hi=19;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(inside_shape(maxx+mid,maxy)){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        bottom=maxx+lo;
        lo=0;hi=19;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(inside_shape(minx,miny-mid)){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        l=miny-lo;
        r=l+(bottom-top);
        if(inside_shape(maxx,maxy+r)==true && inside_shape(maxx,maxy+r+1)==false){
            return true;
        }else{
            return false;
        }
    }
}