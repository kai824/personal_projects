#include "Bruno.h"
#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define f first
#define s second


void Bruno(int n, int l, vector<int> a) {
  vector<pair<char,int> > s;
  for(int i=0;i<a.size();i+=2){
    if(a[i]==1)s.eb('Z',i);
    else if(a[i+1]==0)s.eb('X',i);
    else s.eb('Y',i);
  }
  for(int i=0;i+1<s.size();i++){
    if(s[i].f==s[i+1].f && s[i].f=='Y'){
      Remove(s[i].s);
      s.erase(s.begin()+i);
      i--;
    }
  }
}
