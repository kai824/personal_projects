#include <bits/stdc++.h>
using namespace std;
#include "testlib.h"

int main(int argc, char *argv[]) {

	registerValidation(argc, argv);
  int l,u,a,b;

	int n = inf.readInt(1, 100000, "N");
	inf.readSpace();
  int m = inf.readInt(1, 100000, "M");
	inf.readSpace();
  int r = inf.readInt(1, 1000000, "R");
	inf.readSpace();
  int c = inf.readInt(1, 1000000, "C");
  inf.readEoln();

  ensuref((r*c)<=1000000,"R X C exceeded 1 million");
  ensuref(max(n,m)<=r*c,"N,M <= R*C ");

  for(int i=0;i<n;i++){
    l=inf.readInt(0,r+c-2,"L_i");
    inf.readSpace();
    u=inf.readInt(0,r+c-2,"U_i");
    inf.readEoln();
  }
  set<pair<int,int> > ss;
  for(int i=0;i<m;i++){
    a=inf.readInt(1,r,"A_j");
    inf.readSpace();
    b=inf.readInt(1,c,"B_j");
    inf.readEoln();
    ensuref(ss.find(make_pair(a,b))==ss.end(),"Fan locations not distinct");
    ss.insert(make_pair(a,b));
  }

	inf.readEof();

	return 0;
}
