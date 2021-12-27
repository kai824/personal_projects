// mugger.cpp 30 May 17, 22:27:40 30 0 Judging completed in 4.98s on AWS Oregon.
#include "mugger.h"
using namespace std;
void mugger(int n){
    while(n>0){
        if(n%4==0)n=pick(1);
        else n=pick(n%4);
    }
    if(n==0)answer(false);
	else answer(true);
}