// scrivener.cpp 15 Apr 20, 10:00:04 0 0.71 Judging completed in 5.305s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

int depth[1000005],parent[1000005][20],cur=0;
char t[1000005];

void Init(){
  for(int i=0;i<20;i++)parent[0][i]=-1;
  depth[0]=0;
}

void TypeLetter(char l){
  cur++;
  t[cur]=l;
  depth[cur]=depth[cur-1]+1;
  parent[cur][0]=cur-1;
  for(int i=1;i<20;i++){
    if(parent[cur][i-1]==-1)parent[cur][i]=-1;
    else parent[cur][i]=parent[parent[cur][i-1] ][i-1];
  }
}

void UndoCommands(int u){
  cur++;
  for(int i=0;i<20;i++){
    parent[cur][i]=parent[cur-1-u][i];
  }
  t[cur]=t[cur-u-1];
  cout<<"version "<<cur<<"copied from "<<cur-u-1<<'\n';
}

char GetLetter(int p){
  int up=depth[cur]-1-p,node=cur;
  for(int i=19;i>=0;i--){
    if((1<<i)>=up){
      up-=(1<<i);
      node=parent[node][i];
    }
  }
  return t[node];
}