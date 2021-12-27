// flipbits.cpp 1 Dec 17, 17:03:41 5.01 0.25 Judging completed in 5.863s on AWS Oregon.
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
	if(abs(cnt- (strlen(S)/2) )  <3){
	    return 1;
	}else return 2;
}