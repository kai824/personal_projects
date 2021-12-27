// mugger.cpp 30 May 17, 22:28:39 30 0 Judging completed in 4.224s on AWS Oregon.
#include "mugger.h"
using namespace std;
void mugger(int n){
    while(n>0){
        if(n%4==0)n=pick(3);
        else n=pick(n%4);
    }
    if(n==0)answer(false);
	else answer(true);
}