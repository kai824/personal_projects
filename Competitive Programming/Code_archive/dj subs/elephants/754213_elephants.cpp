// elephants.cpp 13 Aug 20, 21:45:39 26 4.05 Judging completed in 11.218s on AWS Oregon.
#include "elephants.h"
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

int n,l,b=390,m=0,rptr,ind=0,a,cur;
vector<pair<int,pii> > pos[400];
int arr[150005],buck[150005];//original array, which bucket
pii tmp[150005];

void output(){return;
  cerr<<"OUTPUT HERE:\n";
  for(int x=0;x<pos[0].size();x++){
    cerr<<pos[0][x].first<<' '<<pos[0][x].second.first<<' '<<pos[0][x].second.second<<'\n';
  }
  cerr<<"OUTPUT ENDS HERE\n\n";
}

void adjust(int x){//adjust bucket x, assuming stuff in there is alr sorted...
  rptr=pos[x].size()-1;
  for(int i=pos[x].size()-1;i>=0;i--){
    while(pos[x][i].first+l<pos[x][rptr].first)rptr--;
    if(rptr==pos[x].size()-1)pos[x][i].second=mp(1,pos[x][i].first+l);
    else pos[x][i].second=mp(pos[x][rptr+1].second.first+1,pos[x][rptr+1].second.second);//cos rptr stores rightmost other elephant you can group with...
  }
}

int lo,hi,mid;
void init(int N, int L, int X[]){//X already sorted...
  n=N;l=L;
  for(int x=0;x<n;x++){
    arr[x]=X[x];buck[x]=x/b;
    pos[x/b].emplace_back(X[x],mp(-1,-1) );//position, cost, rightmost index covered
    m=max(m,x/b);
  }
  for(int x=0;x<=m;x++){
    adjust(x);
  }
  output();
}
int update(int i, int y){
  ind++;ind%=380;
  if(ind==0){//rebuild...
    arr[i]=y;
    for(int x=0;x<n;x++)tmp[x]=mp(arr[x],x);
    sort(tmp,tmp+n);
    for(int x=0;x<=m;x++)pos[x].clear();
    for(int x=0;x<n;x++){
      pos[x/b].emplace_back(tmp[x].first,mp(-1,-1) );
      buck[tmp[x].second]=x/b;
    }
    for(int x=0;x<=m;x++)adjust(x);
  }else{
    //remove arr[i], add in the new value...
    for(int x=0;x<pos[buck[i]].size();x++){
      if(pos[buck[i]][x].first==arr[i]){//found match!
        pos[buck[i]].erase(pos[buck[i]].begin()+x);break;
      }
    }
    adjust(buck[i]);
    output();
    arr[i]=y;
    for(int x=0;x<=m;x++){
      if(x==m || i<=pos[x].back().first)a=m;//insert into this bucket...
    }
    buck[i]=a;
    pos[a].emplace_back(arr[i],mp(-1,-1) );
    for(int x=pos[a].size()-1;x>0;x--){
      if(pos[a][x-1].first>pos[a][x].first)swap(pos[a][x],pos[a][x-1]);
    }
    adjust(a);
    output();
  }
  //compute new answer...
  cur=pos[0][0].second.first;//cost of covering bucket
  rptr=pos[0][0].second.second;//where will u end?
  for(int x=1;x<=m;x++){
    if(rptr>=pos[x].back().first)continue;//prev bucket can cover this bucket completely... oof
    lo=0;hi=pos[x].size()-1;
    while(lo<hi){
      mid=lo+((hi-lo)/2);
      if(pos[x][mid].first<=rptr)lo=mid+1;//def go beyond that
      else hi=mid;
    }
    cur+=pos[x][lo].second.first;
    rptr=pos[x][lo].second.second;
  }
	return cur;
}
/*
4 10 5
10 15 17 20
2 16 1
1 25 2
3 35 2
0 38 2
2 0 3
*/