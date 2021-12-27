// ans.cpp 28 Mar 20, 13:28:59 44 0.09 Judging completed in 3.984s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

vector<int> adjl[100005];
bool mark[100005];//indicates if it's on the path btw m1 and m2...
int  lw1[100005],lw2[100005];
int subtree_cost[100005];
int nex[100005],back[100005];//trace back from m2 to m1...
int n,k,m1,m2;

int leeway2;

//compute lw1, stating how much we can reduce the cost by...
int t;
int dfs(int node,int prev=-1){
  vector<pair<int,bool> > v;//bool states whether the path is important...
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    if(adjl[node][i]==m2){
      mark[node]=true;
      back[m2]=node;
      nex[node]=m2;
      continue;
    }
    v.emplace_back(dfs(adjl[node][i],node),false);
    if(mark[adjl[node][i]]){
      nex[node]=adjl[node][i];
      mark[node]=true;//we're also on the path...
      back[adjl[node][i]]=node;
      v.back().second=true;
    }
  }
  sort(v.begin(),v.end(),greater<pair<int,bool> >() );
  for(int i=0;i<v.size();i++){
    //v[i].first+=i+1;
    subtree_cost[node]=max(subtree_cost[node],v[i].first+1+i);
  }
  if(v.size()==0)subtree_cost[node]=0;

  int d=0;

  if(mark[node] && v.size()>0){
    for(int i=0;i<v.size();i++){
      if(v[i].second)v[i].first=0;
    }
    sort(v.begin(),v.end(),greater<pair<int,bool> >() );
    for(int i=0;i<v.size();i++)d=max(d,i+1+v[i].first);
    lw1[node]=subtree_cost[node]-d;
    d=0;
    for(int i=0;i<v.size();i++){
      if(v[i].second && i+1<v.size())swap(v[i],v.back());
    }v.pop_back();
    sort(v.begin(),v.end(),greater<pair<int,bool> >() );
    for(int i=0;i<v.size();i++)d=max(d,i+1+v[i].first);
    lw2[node]=subtree_cost[node]-d;
  }
  return subtree_cost[node];
}


int first_it=0;
int dfs2(int node,int prev=-1){
  int ans=0;
  vector<int> v;
  for(int i=0;i<adjl[node].size();i++){
    if(mark[adjl[node][i]])continue;
    if(adjl[node][i]==prev)continue;
    v.push_back(dfs(adjl[node][i],node));
  }
  if(node==m2)v.push_back(-1);
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    if(v[i]+(v.size()-i)>ans){
      ans=v[i]+(v.size()-i);
      first_it=i;
    }
  }
  if(node==m2){
    leeway2=v[first_it]+1;
  }
  return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    if(k==1)cin>>m1;
    else cin>>m1>>m2;
    mark[m2]=true;

    int a,b,c,maxi;
    for(int x=1;x<n;x++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    a=dfs(m1);
    if(m2==0 || m1==m2){
      cout<<a;
      return 0;
    }
    b=dfs2(m2);
    vector<pair<int,int> > v;
    v.emplace_back(m1,0);
    while(v.back().first!=m2){
      v.emplace_back(nex[v.back().first],0);
    }
    for(int i=0;i<v.size();i++){
      //cout<<v[i].first<<' ';
      v[i].second=lw2[v[i].first];
      if(i>0)v[i].second=min(v[i].second,lw1[v[i-1].first]);
      //cout<<v[i].second<<'\n';
    }
    v.pop_back();v.pop_back();
    vector<int> v2;

    int ans=a+b,last_node=m2,cost1=a,cost2=b;
    while(true){
      if(last_node==m2){
        last_node=back[m2];
      }else{
        last_node=back[last_node];
        //calculate cost1...
        c=subtree_cost[last_node];
        cost1=0;
        v2.clear();
        for(int i=0;i<adjl[last_node].size();i++){
          if(mark[adjl[last_node][i]])continue;
          v2.push_back(subtree_cost[adjl[last_node][i]] );
        }
        sort(v2.begin(),v2.end());
        for(int i=0;i<v2.size();i++){
          cost1=max(cost1,int(v2[i]+(v2.size()-i)));
        }
        //discount we got is c-cost1, or v.back.second
        //cout<<c<<' '<<cost1<<'\t'<<v.back().second<<'\t';
        cost1=a-min(c-cost1,v.back().second);
        v.pop_back();
        //cout<<cost1<<'\n';

        //calculate cost2...
        last_node=nex[last_node];
        v2.clear();
        for(int i=0;i<adjl[last_node].size();i++){
          if(mark[adjl[last_node][i]])continue;
          v2.push_back(subtree_cost[adjl[last_node][i]] );
        }
        if(v2.size()>0){
          v2.push_back(-1);
          sort(v2.begin(),v2.end());maxi=0;
          for(int i=0;i<v2.size();i++){
            if(v2[i]+(v2.size()-i)>maxi){
              maxi=v2[i]+(v2.size()-i);
              first_it=i;
            }
          }
          cost2+=maxi+1;
          if(cost2>=leeway2){
            cost2-=leeway2;
            leeway2=0;
          }else{
            leeway2-=cost2;
            cost2=0;
          }
          leeway2+=v2[first_it]+1;
        }else{
          cost2++;
          if(cost2>=leeway2){
            cost2-=leeway2;
            leeway2=0;
          }else{
            leeway2-=cost2;
            cost2=0;
          }
        }
        last_node=back[last_node];
        //cout<<last_node<<' '<<cost2<<' '<<leeway2<<'\n';

        //cout<<last_node<<' '<<cost1<<' '<<cost2<<'\n';

        ans=min(ans,max(cost1,cost2));
      }
      if(last_node==m1)break;
    }
    cout<<ans<<'\n';
    return 0;
}