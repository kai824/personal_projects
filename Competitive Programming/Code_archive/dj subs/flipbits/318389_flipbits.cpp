// flipbits.cpp 24 Jan 18, 09:25:37 0 1 Judging completed in 6.333s on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
int next,ans,prev;
int myrand(void) {
    prev=next;
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % 32768);
}

void mysrand(unsigned seed){
    next = seed;
}
void initialize(){
    while(true){}
    mysrand(time(0));
    ans=myrand();
    next=prev;
}

int guess(char S[]){
    int value=ans;
    for(int x=0;x<200;x++)myrand();
    ans=myrand();
    next=prev;
    if(value%2==0)return 2;
    else return 1;
}