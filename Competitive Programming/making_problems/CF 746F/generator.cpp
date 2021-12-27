#include "bits/stdc++.h"
using namespace std;
#include "testlib.h"

#define rng rnd.next

int main(int argc, char *argv[]) {

	registerGen(argc, argv, 1);

  ios_base::sync_with_stdio(false);

	//start from argv[1], and do atoi
  int n=rng(max(1,atoi(argv[1])-100),atoi(argv[1]) );//200000
  int w=rng(max(1,min(atoi(argv[2]),n)-10 ),min(atoi(argv[2]),n) );//200000
  int k=rng(max(1,atoi(argv[3])-100),atoi(argv[3]) );//1e9

  cout<<n<<' '<<w<<' '<<k<<'\n';

  for(int i=0;i<n;i++){
    //cout<<rng();
		cout<<rng(1,10000);
    if(i+1<n)cout<<' ';
    else cout<<'\n';
  }
	for(int i=0;i<n;i++){
    //cout<<rng();
		cout<<rng(2,10000);
    if(i+1<n)cout<<' ';
    else cout<<'\n';
  }

	return 0;
}
