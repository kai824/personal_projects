// flipbits.cpp 24 Jan 18, 10:41:00 0 0.36 Judging completed in 21.238s on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
typedef long long ll;
ll next,ans,prev;
ll myrand(void) {
    prev=next;
    next = next * 1103515245 + 12345;
    return((unsigned)(next/(INT_MAX*2))%INT_MAX);
}

void mysrand(unsigned seed) {
    next = seed;
}
void initialize(){
    mysrand(time(0));
    ans=myrand();
}

int guess(char S[]){
    ll value=ans;
    for(int x=0;x<200;x++)myrand();
    ans=myrand();
    if(value%2==0)return 2;
    else return 1;
}