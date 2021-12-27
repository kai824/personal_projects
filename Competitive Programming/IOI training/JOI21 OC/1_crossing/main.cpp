#include<bits/stdc++.h>
using namespace std;

string str;
int arr[3][200005];
int pos[200005][9];

struct node{
  int s,e,m,bm=0;//bm for bitmask: 1 for can, 0 for cannot on each bit...
  int j,o,i;//all j, o or i? which ones?
  char lz='-';
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    m=(s+e)/2;
    if(s==e){
      l=r=NULL;
      j=o=i=0;
      for(int k=0;k<9;k++){
        if(pos[s][k]==0)j+=(1<<k);
        else if(pos[s][k]==1)o+=(1<<k);
        else i+=(1<<k);
      }
      if(str[s]=='J')bm=j;
      else if(str[s]=='O')bm=o;
      else bm=i;
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
    if(s<e && lz!='-'){
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
    if(bm >0){
      cout<<"Yes\n";
    }else cout<<"No\n";;
  }
} *root;

int kek[9][3]={
  {0,0,1},
  {0,1,0},
  {1,0,0},//
  {2,2,0},
  {2,0,2},
  {0,2,2},//
  {1,1,2},
  {1,2,1},
  {2,1,1}
};

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
  for(int i=0;i<9;i++){
    //i%3, (i/3)%3, (i/9)%3 --> this list is wrong!
    int a,b,c;
    a=kek[i][0];b=kek[i][1];c=kek[i][2];
    //cout<<"String:"<<a<<' '<<b<<' '<<c<<'\n';
    for(int j=0;j<n;j++){
      pos[j][i]=(arr[0][j]*a+arr[1][j]*b+arr[2][j]*c)%3;
      //cout<<pos[j][i]<<' ';
    }//cout<<'\n';
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
