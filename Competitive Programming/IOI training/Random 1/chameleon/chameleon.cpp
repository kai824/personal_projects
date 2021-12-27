#include "chameleon.h"
#include <bits/stdc++.h>
using namespace std;

namespace{
  vector<int> v;
}
void search(){
  int x=v.back();v.pop_back();

  vector<int> tmp;
  int lo=0,hi=v.size()-1,mid;
  while(lo<hi){
    mid=lo+((hi-lo)/2);
    tmp.clear();
    tmp.push_back(x);
    for(int i=lo;i<=mid;i++)tmp.push_back(v[i]);
    if(Query(tmp)<tmp.size())hi=mid;
    else lo=mid+1;
  }
  //cout<<v[lo]<<' '<<x<<'\n';
  Answer(v[lo],x);
  v.erase(v.begin()+lo);
}

void Solve(int n) {
  v.push_back(1);
  for(int i=2;i<=2*n;i++){
    v.push_back(i);
    if(v.size()==1)continue;
    if(Query(v)<v.size()){//lermao...
      search();
    }
  }

  //Answer(i * 2 + 1, i * 2 + 2);
}
