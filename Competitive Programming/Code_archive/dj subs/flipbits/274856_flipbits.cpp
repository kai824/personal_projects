// flipbits.cpp 1 Dec 17, 17:04:01 6.64 0.21 Judging completed in 5.267s on AWS Oregon.
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
	if(abs(cnt- (strlen(S)/2) )  <4){
	    return 1;
	}else return 2;
}