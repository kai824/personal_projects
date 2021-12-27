#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

pii pts[200005];
vector<int> disc;
map<int,int> mm;

vector<pii> vv[600005];
bool ans[200005];
vector<int> ss[200005];//set of nodes for each...

int par[200005];
int getr(int x){
  if(par[x]==-1)return x;
  return par[x]=getr(par[x]);
}
void merge(int a,int b){
  //if(par[a]!=-1 || par[b]!=-1)cerr<<"WTH\n";
  par[b]=a;
  // if(ss[a].size()<ss[b].size())swap(ss[a],ss[b]);
  // for()
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int r,c,n;
  cin>>r>>c>>n;//c is useless...

  int a,b,d;
  for(int i=0;i<n;i++){
    cin>>pts[i].f>>pts[i].s;
    disc.push_back(pts[i].f-1);
    disc.push_back(pts[i].f);
    disc.push_back(pts[i].f+1);
  }
  sort(disc.begin(),disc.end());
  disc.erase(unique(disc.begin(),disc.end()),disc.end());
  for(int i=0;i<disc.size();i++)mm[disc[i]]=i;
  for(int i=0;i<n;i++){
    pts[i].f=mm[pts[i].f];
    vv[pts[i].f].push_back(mp(pts[i].s,i));

    par[i]=-1;//ufds + set merging things here
    // ss[i].push_back(i);
  }
  for(int i=0;i<disc.size();i++){
    if(vv[i].size()>1)sort(vv[i].begin(),vv[i].end());
  }

  int q;
  cin>>q;
  int p;
  vector<pair<pii,pii> >qq;
  for(int i=0;i<q;i++){
    cin>>a>>b>>c>>d;//x y x y
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
    if(a>c){
      ans[i]=false;
      continue;
    }
    if(a==c){
      //cout<<i<<"THIS EXECUTED!\n";
      ans[i]=(b<=d);
      continue;
    }
    if(mm.find(a)==mm.end() || mm.find(c-1)==mm.end())continue;//leave as false...
    a=mm[a];c=mm[c-1];
    p=upper_bound(vv[c].begin(),vv[c].end(),mp(d,INT_MAX))-vv[c].begin();
    if(p==0)continue;
    if(vv[c][p-1].f<b)continue;
    p=vv[c][p-1].s;//the node to use...
    qq.emplace_back(mp(a,b),mp(p,i));
    //cout<<a<<' '<<b<<' '<<p<<' '<<i<<'\n';
  }
  sort(qq.begin(),qq.end());
  int last=disc.size()-1;//last row that has been "settled"...
  int clast=1e9;//c last...
  set<int> ss;
  for(int i=qq.size()-1;i>=0;i--){
    a=qq[i].f.f;b=qq[i].f.s;p=qq[i].s.f;
    if(a<last){
      while(last>a){
        int p1=vv[last-1].size()-1,p2=vv[last].size()-1;//point last to last-1...
        //if(last==2)cout<<"haha"<<p1<<' '<<p2<<'\n';
        while(p1>=0 && p2>=0){
          if(vv[last-1][p1].f<=vv[last][p2].f){
            merge(vv[last-1][p1].s,vv[last][p2].s);
            p2--;
          }else p1--;//it's too big, so reduce it...
        }

        last--;
      }
      clast=vv[a].size();
      ss.clear();
    }
    while(clast>0 && vv[a][clast-1].f>=b){
      clast--;
      ss.insert(getr(vv[a][clast].s));//getr of the node
    }
    ans[qq[i].s.s]=(ss.find(getr(p))!=ss.end());

  }
  for(int i=0;i<q;i++){
    if(ans[i])cout<<"Yes\n";
    else cout<<"No\n";
  }
  return 0;
}
/*
4 5 2
2 2
3 4
3
2 1 4 5
1 2 1 4
2 3 4 4
*/
