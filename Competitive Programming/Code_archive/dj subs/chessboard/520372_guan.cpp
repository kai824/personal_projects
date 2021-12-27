// guan.cpp 4 May 19, 20:21:13 0 0 Compilation failed on AWS Oregon.
#include "guan.h"
using namespace std;

void guan(int N, int K, char G[][1030]) {
    int i=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(G[x][y]=='H')i^=(x*n)+y
        }
    }
    answer(i/n,i%n);
}