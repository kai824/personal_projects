// flipbits.cpp 24 Jan 18, 10:12:25 0 0.22 Judging completed in 5.614s on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
int next,ans,prev;
int myrand(void) {
    prev=next;
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % 32768);
}

void mysrand(unsigned seed) {
    next = seed;
}
void initialize(){
    mysrand(time(0));
    ans=myrand();
}

int guess(char S[]){
    int value=ans;
    for(int x=0;x<200;x++)myrand();
    ans=myrand();
    if(value%2==0)return 2;
    else return 1;
}