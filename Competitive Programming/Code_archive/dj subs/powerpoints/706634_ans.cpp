// ans.cpp 29 Feb 20, 11:08:10 0 1.03 Judging completed in 5.254s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
#define int long long//learning from chur zhe
typedef pair<int,int> pii;
pii pts[200005];
int xx[200005],yy[200005];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,k,cost=0,sum1=0,sum2=0;
  int minx,maxx,miny,maxy;
  cin>>n>>k;
  for(int x=0;x<n;x++){
    cin>>pts[x].first>>pts[x].second;
    xx[x]=pts[x].first;
    yy[x]=pts[x].second;
  }
  sort(xx,xx+n);
  sort(yy,yy+n);
  minx=xx[0];maxx=xx[n-1];
  miny=yy[0];maxy=yy[n-1];
  vector<pair<pii,pair<int,pii> > > v;//the packages available...
  //reward, cost(no. of ppl), no. of times we can take it, which side is it, x/y index
  //side: 0, 1 for x (small, big)
  //side: 2, 3 for y (small, big)
  for(int i=0;i<n;i++){
    cost+=(i*xx[i])-sum1+(i*yy[i])-sum2;
    sum1+=xx[i];sum2+=yy[i];
    if(i==(n/2))continue;//at the centre, just dao
    if(i<(n/2)){
      v.emplace_back(mp(n-1-i,i+1),mp(xx[i+1]-xx[i],mp(0,i+1) ));
      v.emplace_back(mp(n-1-i,i+1),mp(yy[i+1]-yy[i],mp(2,i+1) ));
    }else{
      v.emplace_back(mp(i,n-i),mp(xx[i]-xx[i-1],mp(1,i-1) ));
      v.emplace_back(mp(i,n-i),mp(yy[i]-yy[i-1],mp(3,i-1) ));
    }
  }
  //cout<<cost<<'\n';
  sort(v.begin(),v.end(),greater<pair<pii,pair<int,pii> > >() );
  sum1=0;
  pair<pii,pii> to_change;//old_val,new_val, no. of times to do it, x/y type...
  to_change.second.first=0;
  for(int i=0;i<v.size();i++){
    //cout<<v[i].first.first<<' '<<v[i].first.second<<' '<<v[i].second.first<<'\n';
    if(v[i].first.second*v[i].second.first<=k){//cost * no. of times we can use
      cost-=v[i].first.first*v[i].second.first * v[i].first.second;//reward * no. of steps * no. of ppl
      k-=v[i].first.second*v[i].second.first;  //cost * "
      if(v[i].second.second.first==0)minx=max(minx,xx[v[i].second.second.second]);
      else if(v[i].second.second.first==1)maxx=min(maxx,xx[v[i].second.second.second]);
      else if(v[i].second.second.first==2)miny=max(miny,yy[v[i].second.second.second]);
      else maxy=min(maxy,yy[v[i].second.second.second]);
    }else{
      sum1=k/v[i].first.second;//move forward as many steps as we can...
      cost-=v[i].first.first*sum1*v[i].first.second;//reward * no. of steps * no. of ppl
      k-=v[i].first.second*sum1;//no. of ppl * no. of steps
      if(v[i].second.second.first==0)minx+=sum1;
      else if(v[i].second.second.first==1)maxx-=sum1;
      else if(v[i].second.second.first==2)miny+=sum1;
      else maxy-=sum1;
      //cout<<"STEPS: "<<sum1<<' '<<sum1*v[i].first.first*v[i].first.second<<'\n';

      sum1=k;//move some of the ppl forward by 1 step...
      cost-=sum1*v[i].first.first - sum1;//no. of ppl * reward

      to_change.second.first=sum1;
      to_change.first.second=v[i].second.second.second;
      if(v[i].second.second.first<=1)to_change.second.second=0;
      else to_change.second.second=1;

      if(v[i].second.second.first==0)to_change.first.first=to_change.first.second-1;
      else if(v[i].second.second.first==1)to_change.first.first=to_change.first.second+1;
      else if(v[i].second.second.first==2)to_change.first.first=to_change.first.second-1;
      else to_change.first.first=to_change.first.second+1;

      if(v[i].second.second.first<=1){
        to_change.first.first=max(min(xx[to_change.first.first],maxx),minx);
        to_change.first.second=max(min(xx[to_change.first.second],maxx),minx);
      }else{
        to_change.first.first=max(min(yy[to_change.first.first],maxy),miny);
        to_change.first.second=max(min(yy[to_change.first.second],maxy),miny);
      }
      while(true){};
      to_change.first.second=max(to_change.first.second,to_change.first.first-1);
      to_change.first.second=min(to_change.first.second,to_change.first.first+1);
      //cout<<"CHANGE: "<<to_change.first.first<<" TO "<<to_change.first.second<<" for "<<to_change.second.first<<" times\n";
      break;
    }
  }
  cout<<cost<<'\n';
  for(int x=0;x<n;x++){
    pts[x].first=max(min(pts[x].first,maxx),minx);
    pts[x].second=max(min(pts[x].second,maxy),miny);
    if(to_change.second.first>0){
      if(to_change.second.second==0){
        if(pts[x].first==to_change.first.first){
          to_change.second.first--;
          pts[x].first=to_change.first.second;
        }
      }else{
        if(pts[x].second==to_change.first.first){
          to_change.second.first--;
          pts[x].second=to_change.first.second;
        }
      }
    }
    cout<<pts[x].first<<' '<<pts[x].second<<'\n';
  }
  return 0;
}