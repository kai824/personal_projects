// ans.cpp 8 Nov 19, 08:24:26 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return(a>b);
}

int parent[300005];
int getr(int x){
    if(parent[x]==-1)return x;
    parent[x]=getr(parent[x]);
    return parent[x];
}

inline void merge(int a,int b){
    a=getr(a);
    b=getr(b);
    if(a==b)return;
    parent[a]=b;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,c;
    long long ans=0,mini=INT_MAX;
    cin>>n>>m;
    pair<int,pair<int,int> > el[m];
    for(int x=1;x<=n;x++){
    	parent[x]=-1;
	}
    for(int x=0;x<m;x++){
        cin>>el[x].second.first>>el[x].second.second>>el[x].first;
    }
    sort(el,el+m,cmp);
    for(int x=0;x<m;x++){
        if(getr(el[x].second.first)!=getr(el[x].second.second)){
            merge(el[x].second.first,el[x].second.second);
            mini=min(mini,el[x].first);
        }
    }
    for(int x=1;x<=n;x++){
        parent[x]=-1;
    }
    sort(el,el+m);
    for(int x=0;x<m;x++){
        if(getr(el[x].second.first)!=getr(el[x].second.second)){
            ans+=el[x].first;
            merge(el[x].second.first,el[x].second.second);
        }
    }
    cout<<ans;
    return 0;
}