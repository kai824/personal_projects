#include <bits/stdc++.h>
using namespace std;
#include "testlib.h"

int main(int argc, char *argv[]) {

	registerValidation(argc, argv);

	int n = inf.readInt(1, 200000, "N");
	inf.readSpace();
  int w = inf.readInt(1, 200000, "W");
	inf.readSpace();
  int k = inf.readInt(1, 1000000000, "K");

	ensuref(w<=n,"W<=N");

  inf.readEoln();

	for(int i=0;i<n;i++){
		inf.readInt(1,10000,"A_i");
		if(i+1<n)inf.readSpace();
		else inf.readEoln();
	}

	for(int i=0;i<n;i++){
		inf.readInt(2,10000,"T_i");
		if(i+1<n)inf.readSpace();
		else inf.readEoln();
	}

	inf.readEof();

	return 0;
}
