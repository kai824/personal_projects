// summit.cpp 14 Nov 16, 21:20:08 100 0 Judging completed in 7.501s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;

uint64_t kd(uint64_t k,int d){
    uint64_t to_divide=1,height_climbed=0;
    for(uint64_t a=0;a==a;a=a+1){
        height_climbed += k/to_divide;
        if(k/to_divide<=0) break;
        to_divide=to_divide*(d+a);
    }
    return height_climbed;
}

int main() {
    uint64_t m,hi,lo=1,mid;
    int d;
    cin>>m>>d;
    hi=m;
    while(hi>lo){
        mid=lo+(hi-lo)/2;
        if(kd(mid,d)>=m) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
    return 0;
}