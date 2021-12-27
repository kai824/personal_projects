// flipbits.cpp 24 Jan 18, 20:08:34 0 0 Compilation failed on AWS Oregon.
#include "flipbits.h"
#include<bits/stdc++.h>
using namespace std;

char cc[200];

void random1(int n)
{
	for(int i = 0; i < n; i++)
	{
		cc[i] = '0' + rand()%2;
	}
}

void random2(int n)
{
	for(int i = 0; i < n; i++)
	{
		cc[i] = '0';
	}
	for(int i = 0; i < n; i++)
	{
		int x = rand()%(i+1);
		if(cc[x] == '1') cc[x] = '0';
		else cc[x] = '1';
	}
}

int def;
void initialize()
{
	srand(time(NULL));
}

int guess(char S[])
{
	int ans=rand()%2;
	if(ans==1)random1(200);
	else random2(200);
	if(ans==0)ans=2;
	return ans;
}