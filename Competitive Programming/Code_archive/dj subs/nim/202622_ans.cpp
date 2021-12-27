// ans.cpp 29 Mar 17, 19:07:30 100 0 Judging completed in 8.659s on AWS Ireland.
#include "nim.h"
#include<bits/stdc++.h>
using namespace std;
int m;//number of stones you can take per turn...
void startGame(int N,int M){
    m=M;
}

int pickStones(int left){//no. of stones left...
    if(left%(m+1)!=0)return(left%(m+1));
    else return 1;
}