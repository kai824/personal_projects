#include "monster.h"
#include <bits/stdc++.h>
using namespace std;

namespace {//global vars here...
int arr[1005];
char dt[1005][1005];
int n;
}

bool beat(int a,int b){
  if(dt[a][b]=='-'){
    if(Query(a,b)){
      dt[a][b]='A';dt[b][a]='B';
    }else{
      dt[a][b]='B';dt[b][a]='A';
    }
  }
  return (dt[a][b]=='A');
}
int find(int k){//find index...
  int ans=0;
  for(int i=0;i<n;i++){
    if(i==k)continue;
    if(beat(k,i))ans++;
  }
  return ans;
}

//Query(a,b) is true if a wins
vector<int> Solve(int N){
  n=N;
  memset(dt,'-',sizeof(dt));

  vector<int> tt,ans(n);
  tt.push_back(0);
  int lo,hi,mid;
  for(int i=1;i<n;i++){
    lo=0;hi=tt.size();
    while(lo<hi){
      mid=lo+((hi-lo)/2);
      if(beat(i,tt[mid])){//tt[mid] is on the right of mid
        lo=mid+1;
      }else{
        hi=mid;
      }
    }
    tt.insert(tt.begin()+lo,i);
  }
  // cerr<<"OUT1"<<'\n';
  // for(int x:tt)cerr<<x<<' ';
  // cerr<<'\n';


  int i0=find(tt[0]),i1,a;
  if(i0==1)i1=find(tt[1]);else i1=-1;
  if(i0==i1){
    if(beat(tt[0],tt[1]))i0--;
    else i1--;
  }else if(i0==1)i0=0;//p.s. i only realised to put this after upsolving...
  //settle first part...
  a=i0+1;
  //cout<<i0<<' '<<i1<<'\n';
  if(a>1)reverse(tt.begin(),tt.begin()+a);
  while(a<n){//index 0 to a-1 is steady...
    int b=a;
    while(!beat(tt[a-1],tt[b])){
      // cerr<<tt[a-1]<<' '<<tt[b]<<'\n';
      b++;
    }
    reverse(tt.begin()+a,tt.begin()+b+1);
    // cerr<<b<<'\n';
    a=b+1;
  }


  // cerr<<"OUT2"<<'\n';
  // for(int x:tt)cerr<<x<<' ';
  // cerr<<'\n';

  for(int i=0;i<tt.size();i++){
    ans[tt[i]]=i;
  }

  return ans;
}
