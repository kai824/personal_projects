#include<bits/stdc++.h>
#include "seat.h"
using namespace std;
typedef long long ll;

vector<int> v;string s;

long long query(const vector<int> &B){
  multiset<int> ss;ll ans=0;
  for(int i=0;i<B.size();i++){
    ss.insert(B[i]);ans+=B[i];
  }

  for(int i=0;i<v.size();i++){
    if(s[i]=='S'){
      if(*ss.begin()<v[i]){
        ans+=(v[i]-*ss.begin());
        ss.erase(ss.begin());
        ss.insert(v[i]);
      }
    }else{
      if(*(--ss.end())>v[i]){
        ans-=(*(--ss.end())-v[i]);
        ss.erase(--ss.end());
        ss.insert(v[i]);
      }
    }
  }
  return ans;
}

void prepare(int N, vector<int> A, string C, int Q) {
  v=A;
  s=C;
}
