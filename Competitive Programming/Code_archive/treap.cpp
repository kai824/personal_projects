#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define mp make_pair
typedef pair<int,int> pii;
#define f first
#define s second

#ifdef local
#define debug(x,label) cerr<<"DEBUG "<<label<<" "<<x<<'\n';
bool deb=true;
#else
#define debug(x,label);
bool deb=false;//for in-code checking
#endif

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define lbd lower_bound
#define upb upper_bound

//const int mod=1000000007 or 998244353;


vector<int> prs;
int aa;
inline int ac(){
  aa=prs.back();prs.pop_back();
  return aa;
}
struct item {
    int v, pr;
    item * l, * r;

    int cnt=1;
    int mndd=1e9,mn=1e9,mx=-1;

    item() { }
    item (int v, int pr) : v(v), pr(pr),l(NULL),r(NULL) {
      cnt=1;
      mn=mx=v;
    }
    void output(){
      if(l!=NULL)l->output();
      cout<<v<<' ';
      if(r!=NULL)r->output();
    }
    void upd(){
      cnt=1;mndd=1e9;
      mn=mx=v;
      if(l){
        cnt+=l->cnt;
        mn=l->mn;
        mndd=min(l->mndd,v-l->mx);
      }
      if(r){
        cnt+=r->cnt;
        mx=r->mx;
        mndd=min(mndd,min(r->mndd,r->mn-v));
      }
    }
};
typedef item * pitem;
pitem root,tmp;
int cnt(pitem k){
  if(k)return k->cnt;
  else return 0;
}
void split_cnt (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    int cur_key = add + cnt(t->l); //implicit key
    if (key <= cur_key)
        split_cnt (t->l, l, t->l, key, add),  r = t;
    else
        split_cnt (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    if(t)t->upd();
}
void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->v)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
}
void merge (pitem & t, pitem l, pitem r) {//merge l,r into t...
    if (!l || !r)//if one of them is NULL, return the other
        t = l ? l : r;
    else if (l->pr > r->pr)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    if(t)t->upd();
}
void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->pr > t->pr)
        split (t, it->v, it->l, it->r),  t = it;
    else
        insert (it->v < t->v ? t->l : t->r, it);
    if(t)t->upd();
}

pitem a,b,c;
void del(pitem &t,int x){//find x, and delete it...
  if(!t)return;
  if(x<t->v)del(t->l,x);
  else if(x>t->v)del(t->r,x);
  else{//delete cur_node
    split_cnt(t,a,b,cnt(t->l));
    split_cnt(b,b,c,1);
    merge(t,a,c);
  }
  t->upd();
}

void spl(int l,int r){
  split_cnt(root,b,c,r+1);
  split_cnt(b,a,b,l);
}

void mnd(int l,int r){
  spl(l,r);
  cout<<b->mndd<<'\n';
  merge(b,b,c);
  merge(root,a,b);
}
void mxd(int l,int r){
  spl(l,r);
  cout<<b->mx-b->mn<<'\n';
  merge(b,b,c);
  merge(root,a,b);
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  string s;int n,a,b;
  cin>>n;

  //initialise priorities...
  for(int i=1;i<=n;i++)prs.push_back(i);
  srand(42);
  for(int i=1;i<n;i++){
    a=rand()%(i+1);
    if(a<i)swap(prs[i],prs[a]);
  }root=NULL;

  for(int i=0;i<n;i++){
    cin>>s;
    if(s=="I"){//insert
      cin>>a;
      tmp=new item(a,ac());
      if(root==NULL)root=tmp;
      else{
        insert(root,tmp);
      }
    }else if(s=="D"){//delete
      cin>>a;
      del(root,a);
    }else if(s=="N"){//min diff
      cin>>a>>b;
      if(a==b)cout<<"-1\n";
      else{
        mnd(a,b);
      }
    }else{//max diff
      cin>>a>>b;
      if(a==b)cout<<"-1\n";
      else mxd(a,b);
    }
    //root->output();cout<<'\n';
  }
  return 0;
}
/*
11
I 1
I 12
I 4
I 8
N 0 3
X 0 3
N 1 3
X 0 2
D 4
N 0 1
X 1 2
*/
