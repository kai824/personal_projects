#include <bits/stdc++.h>
#include "permutation.h"
using namespace std;

bool vis[1000];
void solve(int n) {
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        v.push_back(1+n-i);
    }
    int cur=query(v),c;
    while(cur<n){
      //cout<<cur<<'\n';
      int a=(rand()%n),b=rand()%n;
      if(a==b)continue;
      if(vis[a]||vis[b])continue;
      swap(v[a],v[b]);
      c=query(v);
      if(c>cur){
        if(c-cur>=2){
          vis[a]=vis[b]=true;
        }
        cur=c;
      }else{
        if(cur-c>=2){
          vis[a]=vis[b]=true;
        }
        swap(v[a],v[b]);
      }
    }
}
