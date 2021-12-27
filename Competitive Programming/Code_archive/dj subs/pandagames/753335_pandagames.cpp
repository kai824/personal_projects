// pandagames.cpp 9 Aug 20, 18:19:05 0 0 Compilation failed on AWS Oregon.
#include "pandagames.h"
#include "bits/stdc++.h"
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair

/* ------ The Price is Correct ------ */
/* Subtask 1 */
pii getp(int l,int r){
  if(look(l,r)==r)return mp(l,r);
  else return mp(r,l);
}
pii game1(int n){
  pii v1=getp(1,2),v2;
  for(int i=4;i<=n;i+=2){
    v2=getp(i-1,i);
    v1.first=v1.first+v2.first-look(v1.first,v2.first);
    v1.second=look(v1.second,v2.second);
  }
  if(n%2){v2=mp(n,n);
  v1.first=v1.first+v2.first-look(v1.first,v2.first);
  v1.second=look(v1.second,v2.second);}
  return mp(v1.second,v1.first);
}

/* Subtask 2 */
pii game2(int N){
    return make_pair(1,2);
}

/* Subtask 3 */
int game3(int N){//pyramid vector :)
  int lo,hi,mid,peak;
  lo=1;hi=N-1;
  while(lo<hi){//find the greatest lo where V[lo]<V[lo+1]
    mid=hi-((hi-lo)/2);
    if(look(mid,mid+1)==mid+1)lo=mid;
    else hi=mid-1;
  }
  peak=lo+1;
  //cerr<<"Peak at "<<peak<<'\n';
  if(peak>1){
    lo=1;hi=peak;
    while(lo<hi){
      mid=hi-((hi-lo)/2);
      if(look(N+1,mid)==mid)hi=mid-1;//v[n+1]<v[mid]
      else lo=mid;//v[mid]<=v[n+1]
    }
    //cerr<<"First possible result at "<<lo<<'\n';
    if(look(lo,N+1)==N+1)return lo;
  }
  lo=peak;hi=n;
  while(lo<hi){
    mid=lo+((hi-lo)/2);
    if(look(N+1,mid)==mid)lo=mid+1;//V[mid]>V[n+1]
    else hi=mid;//V[N+1]>=V[mid]
  }
  //cerr<<"Second result at "<<lo<<'\n';
  //cerr<<"CNT: "<<lookcnt<<'\n';
  return lo;
}

/* Subtask 4 */
vector<int> game4(int N) {
    return vector<int>(N);
}

/* ------ Beat the Treap ------ */
/* Subtask 5 */
vector<int> game5(int N, long long seed){
    return vector<int>(N);
}

/* Subtask 6 */
vector<int> game6(int N, long long L, long long R){
    return vector<int>(N);
}