#include "roads.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;
bool debug=false;

vector<ll> minimum_closure_costs(int n, vector<int> u,vector<int> v,vector<int> w){
  //st1: u[i]=0...
  vector<ll> ans;
  vector<pii> edges;
  ll sum=0;
  for(int i=0;i<n-1;i++){
    edges.eb(w[i],v[i]);
    sum+=w[i];
  }
  sort(edges.begin(),edges.end(),greater<pii>() );//from all closed, open edge with highest w first...
  ans.push_back(sum);

  if(debug){
    for(pii x:edges){
      cout<<"debug"<<x.f<<' '<<x.s<<'\n';
    }
  }

  for(int i=1;i<n;i++){
    sum-=edges[i-1].f;
    ans.push_back(sum);
  }
  return ans;
}
