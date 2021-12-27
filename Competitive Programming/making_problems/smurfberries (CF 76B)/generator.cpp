#include "bits/stdc++.h"
using namespace std;
#include "testlib.h"

#define rng rnd.next

set<int> ss;
set<int>::iterator it;
int a;

int main(int argc, char *argv[]) {

	registerGen(argc, argv, 1);

  ios_base::sync_with_stdio(false);

	//start from argv[1], and do atoi
  int n=rng(max(1,atoi(argv[1])-100),atoi(argv[1]) );
  int m=rng(max(0,atoi(argv[2])-100 ),atoi(argv[2]) ),y0,y1;

	y0=rng(0,10000000);
	y1=rng(0,10000000);
	while(y0==y1)y1=rng(0,10000000);

  cout<<n<<' '<<m<<' '<<y0 <<' '<<y1<<'\n';

	for(int i=0;i<n;i++){
		a=rng(-10000000,10000000);
		while(ss.find(a)!=ss.end()){
			a=rng(-10000000,10000000);//change number, hope it's not in the set...
		}
		ss.insert(a);
	}
	for(it=ss.begin();it!=ss.end();it++){
		if(it!=ss.begin())cout<<' ';
		cout<<*it;
	}cout<<'\n';
	ss.clear();


	for(int i=0;i<m;i++){
		a=rng(-10000000,10000000);
		while(ss.find(a)!=ss.end()){
			a=rng(-10000000,10000000);//change number, hope it's not in the set...
		}
		ss.insert(a);
	}
	for(it=ss.begin();it!=ss.end();it++){
		if(it!=ss.begin())cout<<' ';
		cout<<*it;
	}cout<<'\n';
	return 0;
}
