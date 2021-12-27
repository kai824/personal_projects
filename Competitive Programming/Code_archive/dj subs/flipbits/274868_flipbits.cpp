// flipbits.cpp 1 Dec 17, 17:05:51 21.33 0.38 Judging completed in 5.714s on AWS Oregon.
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
	if(abs(cnt- (strlen(S)/2) )  <150){
	    return 1;
	}else return 2;
}