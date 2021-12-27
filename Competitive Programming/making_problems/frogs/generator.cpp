#include <bits/stdc++.h>
using namespace std;
#include "testlib.h"

#define rng rnd.next

set<int> ss;
int a;

int main(int argc, char *argv[]) {

	registerGen(argc, argv, 1);

  ios_base::sync_with_stdio(false);

	//start from argv[1], and do atoi
  int n=rng(max(1,atoi(argv[1])-100),atoi(argv[1]) );
  int m=rng(max(1,atoi(argv[2])-10 ),atoi(argv[2]) );
  int k=rng(max(1,min(n,atoi(argv[3]) )-10 ),min(n,atoi(argv[3]) ) );

  cout<<n<<' '<<m<<' '<<k<<'\n';

  for(int i=0;i<m;i++){
    //cout<<rng();
    if(rng(1,2)==1){
      cout<<rng(1,n);
    }else cout<<rng(1,20);
    if(i+1<m)cout<<' ';
    else cout<<'\n';
  }
  for(int i=0;i<k;i++){
    a=-1;
    while(true){
      a=rng(1,n);
      if(ss.find(a)==ss.end())break;
    }
    ss.insert(a);
    cout<<a;
    if(i+1<k)cout<<' ';
    else cout<<'\n';
  }

	return 0;
}
