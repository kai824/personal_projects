// flipbits.cpp 24 Jan 18, 20:05:19 0 0.48 Judging completed in 4.696s on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
using namespace std;
int def;
void initialize()
{
	srand(0);
	def=rand();
}

int guess(char S[])
{
	srand(0);
	if( (def%2)==1)return 1;
	return 2;
}