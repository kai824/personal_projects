#include<bits/stdc++.h>
using namespace std;

string str;
int arr[3][200005];

struct node{
  int s,e,m;
  bool j,o,i,bm;
  char lz='-';
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    m=(s+e)/2;
    if(s==e){
      l=r=NULL;
      j=o=i=bm=false;
      if(arr[0][s]==0)j=true;
      else if(arr[0][s]==1)o=true;
      else i=true;
      if(str[s]=='J' &&j)bm=true;
      else if(str[s]=='O' &&o)bm=true;
      else if(str[s]=='I' &&i)bm=true;
    }else{
      l=new node(s,m);
      r=new node(m+1,e);
      bm=l->bm&r->bm;

      j=l->j&r->j;//whether this range on pos string is all j/o/i
      o=l->o&r->o;
      i=l->i&r->i;
    }
  }
  void prop(){
    if(lz!='-'){
      l->update(s,e,lz);
      r->update(s,e,lz);
    }
    lz='-';
  }
  void update(int a,int b,char c){
    if(a<=s && e<=b){
      lz=c;
      if(c=='J')bm=j;
      else if(c=='O')bm=o;
      else bm=i;
      return;
    }
    prop();
    if(a<=m)l->update(a,b,c);
    if(m<b)r->update(a,b,c);
    bm=l->bm&r->bm;
  }
  void out(){
    if(bm){
      cout<<"Yes\n";
    }else cout<<"No\n";;
  }
} *root;

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,q;
  cin>>n;
  string ss;
  for(int i=0;i<3;i++){
    cin>>ss;
    for(int j=0;j<n;j++){
      if(ss[j]=='J')arr[i][j]=0;
      else if(ss[j]=='O')arr[i][j]=1;
      else arr[i][j]=2;
    }
  }
  cin>>q;
  cin>>str;
  root=new node(0,n-1);
  root->out();
  int a,b;char c;
  while(q--){
    cin>>a>>b>>c;
    a--;b--;
    root->update(a,b,c);
    root->out();
  }
}
