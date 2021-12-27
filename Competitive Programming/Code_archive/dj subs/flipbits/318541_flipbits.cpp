// flipbits.cpp 24 Jan 18, 16:06:59 0 0.59 Judging completed in 6.666s on AWS Oregon.
#include "flipbits.h"
#include <bits/stdc++.h>
void initialize()
{
	srand(time(NULL)-1);
}
int a;
int guess(char S[])
{
	int ans=rand();
	for(int x=0;x<200;x++)a=rand();
	if( (ans%2)==1) return 1;
	return 2;
}