// ans.cpp 11 Jan 19, 21:42:49 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[100005],p[100005];
int getroot(int a){
    if(parent[a]==-1)return a;
    parent[a]=getroot(parent[a]);
    return parent[a];
}
inline void merge(int a,int b){
    if(getroot(a)!=getroot(b)){
        parent[getroot(a)]=b;
    }
}
inline bool connected(int a,int b){
    return(getroot(a)==getroot(b));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,ans;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>p[x];
    }
    for(int x=0;x<m;x++){
        cin>>a>>b;
        merge(a,b);
    }
    for(int x=1;x<=n;x++){
        if(connected(x,p[x])){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}