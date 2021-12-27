// ans.cpp 14 Feb 19, 17:10:13 100 0.04 Judging completed in 4.816s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
typedef pair<int,bool> pib;
int parent[500005];
bool lazy[500005];//if true, bottom stuff should be flipped(excludes itself)
bool val[500005];
pib get_root(int x){
	if(parent[x]==-1) return make_pair(x,0);//since first one should have no lazy flips
	else{
		pib tmp=get_root(parent[x]);
		parent[x]=tmp.first;
		val[x]^=tmp.second;
		lazy[x]^=tmp.second;
	}
	return make_pair(parent[x],lazy[x]);
}
void merge(int A,int B,bool C){//nodes, whether they repel
  if(get_root(A).first==get_root(B).first)return;//so can just use val from val array
  if( (C==true && val[A]==val[B]) || (C==false && val[A]!=val[B]) ){
  	parent[get_root(A).first]=get_root(B).first;
  }else{
    int aa=get_root(A).first;
    parent[aa]=get_root(B).first;
    val[aa]^=1;
    lazy[aa]^=1;
  }
}
bool connected(int a,int b){
    return(get_root(a).first==get_root(b).first);
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,q,b,c;
  string a;
  cin>>n>>q;
  for(int x=0;x<=n;x++){
    parent[x]=-1;
    lazy[x]=0;val[x]=0;
  }
  for(int x=0;x<q;x++){
    cin>>a>>b>>c;
    if(a=="Q"){//query
      if(connected(b,c)==false){
        cout<<"?\n";
      }else{
        if(val[b]==val[c]){
          cout<<"R\n";
        }else cout<<"A\n";
      }
    }else if(a=="R"){//repel
      merge(b,c,1);
    }else{//attract
      merge(b,c,0);
    }
  }
  return 0;
}