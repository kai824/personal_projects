// ans.cpp 1 Feb 17, 18:44:56 100 0 Judging completed in 14.826s on AWS Ireland.
#include "pingpong.h"
#include<bits/stdc++.h>
using namespace std;

string winner(string s) {
    int pwins=0,rwins=0,pp=0,rp=0;
    for(int x=0;x<s.length();x++){
        if(s[x]=='R')rp++;
        else pp++;
        if(rp>=11 && rp-pp>=2){
            rwins++;
            pp=0;
            rp=0;
        }
        if(pp>=11 && pp-rp>=2){
            pwins++;
            rp=0;
            pp=0;
        }
    }
    if(pwins>rwins){
        return("Potato");
    }else{
        return("Rar");
    }
}