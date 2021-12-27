// sandd.cpp 28 Oct 17, 12:59:34 100 0 Judging completed in 3.556s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#include "sandd.h"
long long process(int x){
    return(supply(x)-demand(x));
}
int getPrice(int p){
    int lo=0,hi=p,mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(process(mid)<0){
            lo=mid+1;
        }else{//process(mid)>=0
            hi=mid;
        }
    }
    return lo;
}