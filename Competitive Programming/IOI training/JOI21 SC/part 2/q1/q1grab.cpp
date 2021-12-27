#include<bits/stdc++.h>
using namespace std;

#define int long long
const int inf=LLONG_MAX;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>

deque<pii> dq[65005];//size, type...

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,q;
  cin>>n>>m>>q;
  int a,b,c,d,e;
  while(q--){
    cin>>a;
    if(a==1){
      cin>>b>>c>>d>>e;
      for(int i=b;i<=c;i++){
        dq[i].eb(e,d);
      }
    }else if(a==2){
      cin>>b>>c>>d;
      for(int i=b;i<=c;i++){
        int e=d;
        while(e>0 && dq[i].size()>0){
          if(dq[i][0].f<=e){
            e-=dq[i][0].f;
            dq[i].pop_front();
          }else{
            dq[i][0].f-=e;
            e=0;
          }
        }
      }
    }else{
      cin>>b>>c;//cth customer...
      if(n<=2000){
        for(pii x:dq[b]){
          c-=x.f;
          if(c<=0){
            cout<<x.s<<'\n';
            goto end;
          }
        }
        cout<<"0\n";
        end:;
      }else{
        if(dq[b].size()>=c)cout<<dq[b][c-1].s<<'\n';
        else cout<<"0\n";
      }
    }
  }
  return 0;
}
