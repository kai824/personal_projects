#include <bits/stdc++.h>
using namespace std;
#include "testlib.h"

int main(int argc, char *argv[]) {

	registerValidation(argc, argv);

	int n = inf.readInt(1, 500000, "N");

  inf.readEoln();

	for(int i=0;i<n;i++){
		char c=inf.readChar();
		ensuref( (c=='0'||c=='1'), "S_i in [0,1]");
	}

	inf.readEoln();
	inf.readEof();

	return 0;
}
