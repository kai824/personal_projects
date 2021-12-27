// ans.cpp 21 Jul 20, 23:08:35 100 0.7 Judging completed in 5.363s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
#define pi pair<int,int>

int arr[200005],ans[200005],cnt[1000005],cur;

vector<pair<pi,int> > quer[450];

bool cmp(pair<pi,int>a,pair<pi,int>b){
  return a.first.second<b.first.second;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,a,b;
    cin>>n;
    for(int x=0;x<n;x++)cin>>arr[x];
    cin>>q;
    for(int x=0;x<q;x++){
      cin>>a>>b;
      a--;b--;
      quer[a/450].emplace_back(mp(a,b),x);
    }
    for(int i=0;i<450;i++){
      if(quer[i].size()==0)continue;
      sort(quer[i].begin(),quer[i].end(),cmp);
      cur=0;
      for(int j=quer[i][0].first.first;j<=quer[i][0].first.second;j++){
        cnt[arr[j]]++;
        if(cnt[arr[j]]==1)cur++;
      }
      ans[quer[i][0].second]=cur;
      //cout<<"HMM OK "<<cur<<' '<<quer[i][0].second;
      for(int j=1;j<quer[i].size();j++){
        if(quer[i][j-1].first.second<=quer[i][j].first.second){//expand
          for(int x=quer[i][j-1].first.second+1;x<=quer[i][j].first.second;x++){
            cnt[arr[x]]++;
            if(cnt[arr[x]]==1)cur++;
          }
        }else{
          assert(false);
        }
        if(quer[i][j-1].first.first<=quer[i][j].first.first){
          for(int x=quer[i][j-1].first.first;x<quer[i][j].first.first;x++){//reduce
            cnt[arr[x]]--;
            if(cnt[arr[x]]==0)cur--;
          }
        }else{
          for(int x=quer[i][j].first.first;x<quer[i][j-1].first.first;x++){//expand
            cnt[arr[x]]++;
            if(cnt[arr[x]]==1)cur++;
          }
        }

        ans[quer[i][j].second]=cur;
        //cout<<"HMM "<<cur<<' '<<quer[i][j].second<<'\n';
      }
      for(int x=quer[i].back().first.first;x<=quer[i].back().first.second;x++){
        cnt[arr[x]]=0;
      }
    }
    for(int x=0;x<q;x++){
      cout<<ans[x]<<'\n';
    }
    return 0;
}