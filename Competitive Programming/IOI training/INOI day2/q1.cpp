#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

int arr[200005];
int plis[200005],slis[200005];//prefix and suffix lis length...
vector<int> lis;

vector<int> hz[200005];int nex=0;
int ind[200005];

int previ[200005];
vector<pii> bt;
void trim(){
  int it;
  //cerr<<"TRIM DEBUGGING:\n";
  for(int i=0;i<nex;i++){
    bt.clear();bt.emplace_back(hz[i][0],0);
    previ[0]=-1;
    for(int j=1;j<hz[i].size();j++){
      if(hz[i][j]>bt.back().first){
        previ[j]=bt.back().second;
        bt.emplace_back(hz[i][j],j);
      }else{
        it=upper_bound(bt.begin(),bt.end(),make_pair(hz[i][j],INT_MAX))-bt.begin();
        if(it==0)previ[j]=-1;
        else previ[j]=bt[it-1].second;
        bt[it]=make_pair(hz[i][j],j);
      }
    }
    for(int j=0;j<hz[i].size();j++)hz[i][j]=-hz[i][j];

    it=bt.back().second;
    do{
      hz[i][it]=-hz[i][it];
      it=previ[it];
    }while(it!=-1);

    //for(int x:hz[i])cout<<x<<' ';cout<<'\n';
  }
  //cerr<<"END OF TRIM DEBUGGING\n";
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,a,ans=0;
  cin>>n;
  while(n--){
    cin>>a;
    for(int i=0;i<a;i++)cin>>arr[i];

    plis[0]=1;
    lis.clear();lis.push_back(arr[0]);
    for(int i=1;i<a;i++){
      if(lis.back()<arr[i])lis.push_back(arr[i]);
      else{
        int it=upper_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
        lis[it]=arr[i];
      }
      plis[i]=lis.size();
    }
    slis[a-1]=1;
    lis.clear();lis.push_back(arr[a-1]);
    for(int i=a-2;i>=0;i--){
      if(lis.back()<arr[i])lis.push_back(arr[i]);
      else{
        int it=upper_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
        lis[it]=arr[i];
      }
      slis[i]=lis.size();
    }

    if(a==1){
      ans++;
      hz[nex++].push_back(arr[0]);
      continue;
    }

    pair<int,int> bb=make_pair(0,0);
    for(int i=0;i+1<a;i++){
      bb=max(bb,make_pair(plis[i]+slis[i+1],i));
    }
    ans+=bb.first;
    //cerr<<"Sizes"<<bb.second<<' '<<a-1-bb.second<<'\n';

    for(int i=0;i<=bb.second;i++){
      hz[nex].push_back(arr[i]);
    }nex++;
    for(int i=a-1;i>bb.second;i--){
      hz[nex].push_back(arr[i]);
    }nex++;
  }
  cout<<ans<<'\n';

  priority_queue<pii,vector<pii>,greater<pii> > pq;//smallest first: (value, index)
  trim();
  for(int i=0;i<nex;i++)pq.emplace(hz[i][0],i);
  bool first=true;
  while(!pq.empty()){
    int a=pq.top().second;
    pq.pop();
    if(!first)cout<<' ';
    first=false;
    cout<<abs(hz[a][ind[a]]);
    ind[a]++;
    if(ind[a]<hz[a].size()){
      pq.emplace(hz[a][ind[a]],a);
    }
  }
  return 0;
}
/*
3
4 7 2 3 5
3 1 11 9
4 10 4 8 6
*/
