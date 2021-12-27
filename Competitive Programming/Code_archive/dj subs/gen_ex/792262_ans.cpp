// ans.cpp 22 Nov 20, 22:54:25 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int pa[600005],siz[600005];

priority_queue<int> pq[600005];

int getr(int x){
    if(pa[x]==-1)return x;
    pa[x]=getr(pa[x]);
    return pa[x];
}
bool merge(int a,int b){
    a=getr(a);
    b=getr(b);
    if(a==b)return true;
    if(siz[a]<siz[b])swap(a,b);
    siz[a]+=siz[b];siz[b]=0;
    pa[b]=a;
    while(!pq[b].empty()){
        pq[a].push(pq[b].top());
        pq[b].pop();
    }
    cout<<pq[a].top()<<'\n';
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a,b;
    cin>>n>>k;
    for(int x=1;x<=n;x++){
        cin>>a;
        pq[x].push(a);
        pa[x]=-1;
        siz[x]=1;
    }
    for(int x=0;x<m;x++){
        cin>>a>>b;
        if(a==-1){
            b=getr(b);
            if(siz[b]==1)cout<<"-1\n";
            else{
                pq[b].pop();siz[b]--;
                cout<<pq[b].top()<<'\n';
            }
        }else{
            if(merge(a,b)){
                cout<<"-1\n";
            }
        }
    }
    return 0;
}