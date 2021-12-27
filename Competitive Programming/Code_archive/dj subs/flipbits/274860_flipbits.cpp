// flipbits.cpp 1 Dec 17, 17:04:34 21.27 0.22 Judging completed in 4.895s on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
using namespace std;

void initialize()
{
	
}
int guess(char S[]){
    int cnt=0;
	for(int x=0;x<strlen(S);x++){
	    if(S[x]=='1')cnt++;
	}
	if(abs(cnt- (strlen(S)/2) )  <20){
	    return 1;
	}else return 2;
}