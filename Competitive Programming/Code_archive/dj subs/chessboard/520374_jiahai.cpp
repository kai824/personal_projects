// jiahai.cpp 4 May 19, 20:24:52 100 0.12 Judging completed in 6.876s on AWS Oregon.
#include "jiahai.h"
using namespace std;

void jiahai(int n, int K, int X, int Y, char G[][1030]) {
    int i=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(G[x][y]=='H')i^=(x*n)+y;
        }
    }
    i^=(X*n)+Y;
    flip(i/n,i%n);
}