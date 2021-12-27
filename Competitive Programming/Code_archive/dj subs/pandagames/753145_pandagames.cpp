// pandagames.cpp 9 Aug 20, 17:38:01 0 0.14 Judging completed in 5.235s on AWS Oregon.
#include <bits/stdc++.h>
#include "pandagames.h"
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair

/* ------ The Price is Correct ------ */
/* Subtask 1 */
pii recurse(int l,int r){
  if(l==r)return mp(l,r);
  if(r-l==1){
    if(look(l,r)==r)return mp(l,r);
    else return mp(r,l);
  }
  pii v1,v2;
  v1=recurse(l,(l+r)/2);
  v2=recurse((l+r)/2+1,r);
  v1.first=v1.first+v2.first-look(v1.first,v2.first);//min(a,b)=a+b-max(a,b)
  v1.second=look(v1.second,v2.second);
  return v1;
}
pii game1(int n){
  return recurse(1,n);//min, max
}

/* Subtask 2 */
pair<int,int> game2(int N){
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