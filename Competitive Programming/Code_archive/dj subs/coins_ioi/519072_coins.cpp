// coins.cpp 28 Apr 19, 15:02:33 100 0 Judging completed in 6.768s on AWS Oregon.
#include "coins.h"
#include<bits/stdc++.h>
using namespace std;

vector<int> coin_flips(vector<int> b, int c) {
    vector<int> flips;
    int g=0;
    for(int x=0;x<64;x++){
        if(b[x]==1) g^=x;
    }
    flips.push_back(g^c);
    return flips;
}

int find_coin(vector<int> b) {
    int g=0;
    for(int x=0;x<64;x++){
        if(b[x]==1)g^=x;
    }
    return g;
}