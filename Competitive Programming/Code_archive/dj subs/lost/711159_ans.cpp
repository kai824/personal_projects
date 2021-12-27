// ans.cpp 10 Mar 20, 14:12:21 0 0 Compilation failed on AWS Oregon.
#include "lost.h"
#include "bits/stdc++.h"
using namespace std;

map<int,int> mp;
bool mush[65540];

void plant_mushrooms(int n){
  int cnt=16,bm=0;
  for(int x=1;x<=n;x++){
    for(int i=x+cnt;i<x+17 && i<=n;i++){
      mush[i]=1;
      plant_mushroom_on(i);
    }
    cnt--;
    x+=16;
  }
  for(int x=1;x<=16;x++){
    bm*=2;
    if(mush[x])bm++;
  }
  for(int x=17;x<=n;x++){
    bm*=2;
    bm%=(1<<16);
    if(mush[x])bm++;
    mp[bm]=x;
  }
}

void play_game(){
  int q=0;
  if(check_mushroom())q++;
  for(int i=0;i<16;i++){
    if(walk_left()==false)return i+1;
    if(check_mushroom())q+=(1<<(i+1) );
  }
  answer(mp[q]);
}