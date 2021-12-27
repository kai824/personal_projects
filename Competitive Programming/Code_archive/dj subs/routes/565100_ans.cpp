// ans.cpp 19 Oct 19, 16:18:33 100 0.35 Judging completed in 4.501s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
int parent[500005];
bool lazy[500005],odd[500005];//whether it contains an odd cycle...
//bool col[500005];
//col is 0 if dist from root is even...

int get_root(int x){
    if(parent[x]==-1)return x;
    int a=parent[x];
    parent[x]=get_root(a);
    if(lazy[a]){
        lazy[x]=!lazy[x];
    }
    return parent[x];
}

inline void combine(int aa,int bb){
    int a=get_root(aa),b=get_root(bb);
    if(a==b){
        if(lazy[aa]==lazy[bb]){
            odd[a]=true;
        }
        return;
    }
    parent[a]=bb;
    odd[b]|=odd[a];
    if(lazy[aa]==false)lazy[a]=true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,e,d,a,b;
    cin>>n>>e>>d;
    for(int x=0;x<500005;x++){parent[x]=-1;}
    for(int x=0;x<e;x++){
        cin>>a>>b;
        combine(a,b);
    }
    /*for(int x=0;x<n;x++){
      cout<<get_root(x)<<' ';
    }cout<<'\n';
    for(int x=0;x<n;x++){
      cout<<lazy[x]<<' ';
    }cout<<"\n\n";*/
    for(int x=0;x<d;x++){
        cin>>a>>b;
        if(get_root(a)!=get_root(b)){
            cout<<"none\n";
        }else if(odd[get_root(a)]){
            cout<<"both\n";
        }else{
            if(lazy[a]^lazy[b]){
                cout<<"odd\n";
            }else cout<<"even\n";
        }
    }
    return 0;
}