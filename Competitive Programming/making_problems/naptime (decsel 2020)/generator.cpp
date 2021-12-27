#include "bits/stdc++.h"
using namespace std;
#include "testlib.h"

#define rng rnd.next

bool marked[1000005];

int main(int argc, char *argv[]) {

	registerGen(argc, argv, 1);

  ios_base::sync_with_stdio(false);

	int max_rc,n,m,r,c;
  bool lu=(argv[2][0]=='1'),l0=(argv[3][0]=='1');

  int l,u,tmp,a,b;

  if(argv[1][0]=='-'){
    r=atoi(argv[4]);c=atoi(argv[5]);
    n=rng(1,min(100000,r*c));m=rng(1,min(100000,r*c));
  }else if(argv[1][0]=='+'){
    r=atoi(argv[4]);c=atoi(argv[5]);
    n=atoi(argv[6]);m=atoi(argv[7]);
  }else{
    max_rc = atoi(argv[1]);
  	r=rng(1,max_rc);c=rng(1,max_rc/r);
    n=rng(1,min(100000,r*c));m=rng(1,min(100000,r*c));
  }
	cout<<n<<' '<<m<<' '<<r<<' '<<c<<'\n';

  for(int i=0;i<n;i++){
    if(l0)l=0;
    else l=rng(0,r+c-2);
    if(lu)u=l;
    else u=rng(l,r+c-2);
    cout<<l<<' '<<u<<'\n';
  }

  vector<int>v;
  set<int>ss;
  for(int j=0;j<min(m,r*c-m);j++){
    tmp=rng(0,r*c-1);
    while(ss.find(tmp)!=ss.end()){
      tmp=rng(0,r*c-1);
    }
    ss.insert(tmp);
  }
  if(m<=(r*c-m)){//picked m numbers...
    for(auto it=ss.begin();it!=ss.end();it++){
      v.push_back(*it);
    }
  }else{
    for(int i=0;i<r*c;i++){
      if(ss.find(i)==ss.end())v.push_back(i);
    }
  }
  shuffle(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    a=v[i]/c;
    b=v[i]%c;
    a++;b++;
    cout<<a<<' '<<b<<'\n';
  }

	return 0;
}
