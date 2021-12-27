// pandagames.cpp 9 Aug 20, 17:44:10 0 0.16 Judging completed in 7.075s on AWS Oregon.
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
  return v1;
}

/* Subtask 2 */
pii game2(int N){
    return make_pair(1,2);
}

/* Subtask 3 */
int game3(int N){
    return 1;
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