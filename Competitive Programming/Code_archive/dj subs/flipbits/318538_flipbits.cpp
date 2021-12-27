// flipbits.cpp 24 Jan 18, 16:05:58 0 0.6 Judging completed in 5.103s on AWS Oregon.
#include "flipbits.h"
#include <bits/stdc++.h>
void initialize()
{
	srand(time(NULL));
}

int guess(char S[])
{
	int ans=rand();
	for(int x=0;x<200;x++)rand();
	if( (ans%2)==1) return 1;
	return 2;
}