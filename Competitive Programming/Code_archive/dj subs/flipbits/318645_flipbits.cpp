// flipbits.cpp 24 Jan 18, 20:10:40 0 0.67 Judging completed in 5.355s on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
using namespace std;

char ccc[200];

void random1(int n)
{
	for(int i = 0; i < n; i++)
	{
		ccc[i] = '0' + rand()%2;
	}
}

void random2(int n)
{
	for(int i = 0; i < n; i++)
	{
		ccc[i] = '0';
	}
	for(int i = 0; i < n; i++)
	{
		int x = rand()%(i+1);
		if(ccc[x] == '1') ccc[x] = '0';
		else ccc[x] = '1';
	}
}

int def;
void initialize()
{
	srand(time(NULL)-1);
}

int guess(char S[])
{
	int ans=rand()%2;
	if(ans==1)random1(200);
	else random2(200);
	if(ans==0)ans=2;
	return ans;
}