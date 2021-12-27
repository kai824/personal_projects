// caesar.cpp 23 Apr 17, 16:05:26 0 0 Compilation failed on AWS Ireland.
#include "caesar.h"
#include <bits/stdc++.h>
using namespace std;
string stored;
int cs=0;//current shift
void loadCipher(string plaintext) {
	stored=plaintext;
	cs=0;
}
void shift(int x) {
	cs+=x;
	cs%=26;
	if(cs<0){
	    cs+=26;
	}
}
char getLetter(int position) {
	int a=(int)stored[position-1];
	a-=65;
	a+=cs;
	a%=26;
	a+=65;
	return ((char)a);
}