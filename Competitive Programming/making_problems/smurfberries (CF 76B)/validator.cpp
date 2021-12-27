#include "bits/stdc++.h"
using namespace std;
#include "testlib.h"

int main(int argc, char *argv[]) {

	registerValidation(argc, argv);

	int n = inf.readInt(1, 100000, "N");
	inf.readSpace();
  int m = inf.readInt(0, 100000, "M");
	inf.readSpace();
  int y0 = inf.readInt(0, 10000000, "Y_0");
	inf.readSpace();
  int y1 = inf.readInt(0, 10000000, "Y_1");

  inf.readEoln();

	int prev=INT_MIN,tmp;

	for(int i=0;i<n;i++){
		tmp=inf.readInt(-10000000,10000000,"line 2");
		ensuref(prev<tmp,"Line 2 not strictly increasing");
		prev=tmp;
		if(i+1<n)inf.readSpace();
		else inf.readEoln();
	}
	prev=INT_MIN;
	for(int i=0;i<m;i++){
		tmp=inf.readInt(-10000000,10000000,"line 3");
		ensuref(prev<tmp,"Line 3 not strictly increasing");
		prev=tmp;
		if(i+1<m)inf.readSpace();
		else inf.readEoln();
	}

	inf.readEof();

	return 0;
}
