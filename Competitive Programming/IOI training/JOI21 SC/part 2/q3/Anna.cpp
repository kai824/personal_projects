#include "Anna.h"
#include <bits/stdc++.h>
using namespace std;

namespace {


} // namespace

void Anna(int N, int K,vector<int> R, vector<int> C) {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      int kek=0;
      for(int i=0;i<K;i++){
        int b=0;
        if(r<R[i])b=1;
        else if(r>R[i])b=0;
        else{
          if(c>=C[i])b=0;
          else b=(C[i]-c)%2;
        }
        if(b>0)kek+=(1<<i);
      }
      SetFlag(r, c, kek+1);
    }
  }
}
