// guan.cpp 4 May 19, 20:24:52 100 0.12 Judging completed in 6.876s on AWS Oregon.
#include "guan.h"
using namespace std;

void guan(int n, int K, char G[][1030]) {
    int i=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(G[x][y]=='H')i^=(x*n)+y;
        }
    }
    answer(i/n,i%n);
}