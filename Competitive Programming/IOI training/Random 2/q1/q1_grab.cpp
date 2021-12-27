#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

vector<int> oo[2505];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int r,c,n;
  cin>>r>>c>>n;
  int a,b,d;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    oo[a].push_back(b);
  }
  for(int i=0;i<=r;i++){
    if(oo[i].size()>0)sort(oo[i].begin(),oo[i].end());
  }
  int q;
  cin>>q;
  while(q--){
    cin>>a>>b>>c>>d;
    int cur=b;
    if(a>c)goto hell;
    for(int j=a;j<c;j++){
      if(oo[j].size()==0 || oo[j].back()<cur)goto hell;
      cur=*lower_bound(oo[j].begin(),oo[j].end(),cur);
      if(cur>d)goto hell;
    }
    if(cur>d)goto hell;
    cout<<"Yes\n";continue;

    hell:;
    cout<<"No\n";
  }
}
