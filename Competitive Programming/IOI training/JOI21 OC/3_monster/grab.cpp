#include "monster.h"
#include <bits/stdc++.h>
using namespace std;

namespace {//global vars here...
int arr[1005];
bool dt[1005][1005];
}
//Query(a,b) is true if a wins
vector<int> Solve(int n) {
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      dt[i][j]=Query(i,j);
      if(dt[i][j])arr[i]++;
      else arr[j]++;
    }
    ans[i]=arr[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(ans[i]!=ans[j])continue;
      if(ans[i]==1){//one is 0, one should be 1
        if(!dt[i][j])ans[j]--;
        else ans[i]--;
      }else{
        if(!dt[i][j])ans[i]++;
        else ans[j]++;
      }
    }
  }
  for(int x:ans)cout<<x<<'\n';

  return ans;
}
