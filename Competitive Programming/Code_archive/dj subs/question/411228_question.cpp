// question.cpp 12 Nov 18, 15:59:49 0 1.11 Judging completed in 8.423s on AWS Oregon.
#include "question.h"
using namespace std;
int xx[2000005],it=0;
bool queried=false;
void Init(int N){

}

int Alice(int x,int y){
    xx[it]=x;
    it++;
    return 1;
}

int Bob(int q,int h){
    if(queried==0){
        it=0;
    }
    int ans;
    if(q==xx[it])ans=1;
    else ans=0;
    it++;
    return ans;
}