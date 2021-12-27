// ans.cpp 6 Sep 17, 22:36:18 43 1 Judging completed in 9.782s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[100005],rank1[100005];
pair<int,int> p[100005];
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
bool checkifconnected(int a,int b){
    return(get_root(a)==get_root(b));
}
void merge(int A,int B){
	if(checkifconnected(A,B))return;
	parent[get_root(A)]=get_root(B);
}
int main() {
    int tc,n,m,a,b;
    bool cor;
    cin>>tc;
    while(tc--){
        fill_n(parent,100005,-1);
        fill_n(rank1,100005,0);
        cin>>n>>m;
        for(int x=0;x<n;x++){
            cin>>a;
            p[a].first=x;
        }
        for(int x=0;x<n;x++){
            cin>>a;
            p[a].second=x;
        }
        for(int x=0;x<m;x++){
            cin>>a>>b;
            a--;
            b--;
            merge(a,b);
        }
        cor=true;
        for(int x=0;x<n;x++){
        	if(p[x].first==p[x].second)continue;
            if(!checkifconnected(p[x].first,p[x].second)){
                cor=false;
                break;
            }
        }
        if(cor)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}