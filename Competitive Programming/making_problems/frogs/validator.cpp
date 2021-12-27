#include "bits/stdc++.h"
using namespace std;
#include "testlib.h"

set<int> ss;

int main(int argc, char *argv[]) {

	registerValidation(argc, argv);

	int n = inf.readInt(1, 1000000000, "N");
	inf.readSpace();
  int m = inf.readInt(1, 100, "M");
	inf.readSpace();
  int k = inf.readInt(1, 100, "K");

  inf.readEoln();

	for(int i=0;i<m;i++){
		inf.readInt(1,1000000000,"D_i");
		if(i+1<m)inf.readSpace();
		else inf.readEoln();
	}

	for(int i=0;i<k;i++){
		int a=inf.readInt(1,1000000000,"Mosquito_pos");

		ensuref(ss.find(a)==ss.end(),"Mosquitoes not distinct");
		ss.insert(a);

		if(i+1<k)inf.readSpace();
		else inf.readEoln();
	}

	inf.readEof();

	return 0;
}
