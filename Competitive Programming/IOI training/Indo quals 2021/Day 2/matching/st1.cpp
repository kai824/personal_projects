#include "matching.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

int count_matching(int n, int m, int a, int b, vector<int> u, vector<int> v){
  bool mk[n];memset(mk,0,sizeof(mk));
  for(int i=0;i<m;i++){u[i]--;v[i]--;}
  int ans=0;
  for(int i=0;i<(1<<m);i++){
    bool ok=true;
    for(int j=0;j<m;j++){
      if(i&(1<<j)){
        if(mk[u[j]]||mk[v[j]]){
          ok=false;
        }
        mk[u[j]]=true;
        mk[v[j]]=true;
      }
    }
    for(int j=0;j<m;j++){
      mk[u[j]]=mk[v[j]]=false;
    }
    if(ok)ans++;
  }
  return ans;
}
