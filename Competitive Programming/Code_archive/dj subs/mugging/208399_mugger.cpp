// mugger.cpp 30 May 17, 22:26:28 5 0 Judging completed in 4.702s on AWS Oregon.
#include "mugger.h"
using namespace std;
void mugger(int n){
    while(n>0){
        n=pick(n%4);
    }
	answer(true);
}