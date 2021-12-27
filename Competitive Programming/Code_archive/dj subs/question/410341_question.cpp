// question.cpp 12 Nov 18, 11:58:10 0 1.17 Judging completed in 8.876s on AWS Oregon.
#include "question.h"
using namespace std;
int a[1000];
void Init(int n){
    int cur_it=0;
    for(int x1=0;x1<12;x1++){
        for(int x2=x1;x2<12;x2++){
            for(int x3=x2;x3<12;x3++){
                for(int x4=x3;x4<12;x4++){
                    for(int x5=x4;x5<12;x5++){
                        for(int x6=x5;x6<12;x6++){
                            a[cur_it]=(1<<x1)+(1<<x2)+(1<<x3)+(1<<x4)+(1<<x5)+(1<<x6);
                            cur_it++;
                            if(cur_it>n)return;
                        }
                    }
                }
            }
        }
    }
}

int Alice(int xx,int yy){
    // returns the value h for Bob
    for(int x=0;x<12;x++){
        if( (((1<<x)&a[xx])!=0) && (((1<<x)&a[yy])==0) ){
            return x+1;
        }
    }
    return 1;
}

int Bob(int q,int h){
    h--;
    //returns 1 if the answer is "yes", and 0 if the answer is "no"
    if(((1<<h)&a[q])==0)return 0;
    else return 1;
}