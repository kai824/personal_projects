// flipbits.cpp 1 Dec 17, 17:05:27 21.33 0.2 Judging completed in 4.807s on AWS Oregon.
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
	if(abs(cnt- (strlen(S)/2) )  <70){
	    return 1;
	}else return 2;
}