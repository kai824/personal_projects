// ans.cpp 5 Dec 17, 21:53:48 20 0.01 Judging completed in 5.307s on AWS Oregon.
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;

int valid(int n, int in[]){
    vector<int>v;
    int expected=-1;
    for(int x=0;x<n;x++){
        if(in[x]>n)v.push_back(in[x]);
        else if(expected!=-1){
            if(expected!=in[x]){//input not what you expect...
                return 0;
            }
        }else{
        	expected=in[x];
        }
        if(expected!=-1){
            expected++;
            if(expected>n)expected=1;
        }
    }
    sort(v.begin(),v.end());
    for(int x=1;x<v.size();x++){
        if(v[x]==v[x-1]){
            return 0;
        }
    }
    return 1;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
    return 0;
}

int countReplacement(int n, int inputSeq[]) {
    return 0;
}