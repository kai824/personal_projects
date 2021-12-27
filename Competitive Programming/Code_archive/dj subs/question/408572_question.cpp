// question.cpp 10 Nov 18, 19:43:20 0 1.13 Judging completed in 12.401s on AWS Oregon.
#include "question.h"
using namespace std;
int xx=0;
void Init(int N){
return;
}

int Alice(int x,int y){
    xx=x;
    // returns the value h for Bob
    return x;
}

int Bob(int q,int h){
    //returns 1 if the answer is "yes", and 0 if the answer is "no"
    if(q==xx)return 1;
    else return 0;
}