#include "tree.h"
#include<bits/stdc++.h>
using namespace std;
//i swear if this works

int ind[200005];
int eh[200005];//expected height*2

double count_average_height(int n, vector<int> dfs, vector<int> bfs) {
  for(int i=0;i<n;i++)ind[dfs[i]]=i;
  eh[bfs[0]]=2;
  eh[bfs[1]]=4;
  for(int i=2;i<n;i++){
    if(ind[bfs[i-1]]+1==ind[bfs[i]]){
      if(bfs[i-1]<bfs[i])eh[bfs[i]]=eh[bfs[i-1]]+1;//child or sibling
      else eh[bfs[i]]=eh[bfs[i-1]]+2;//cannot sibling
    }else if(ind[bfs[i-1]]<ind[bfs[i]]) eh[bfs[i]]=eh[bfs[i-1]];//definitely sibling
    else{
      eh[bfs[i]]=eh[bfs[i-1]]+2;
    }

    #ifdef loc
    cout<<bfs[i]<<' '<<eh[bfs[i]]<<'\n';
    #endif
  }

  double ans=eh[bfs.back()];
  ans/=2.0;
  return ans;
}
