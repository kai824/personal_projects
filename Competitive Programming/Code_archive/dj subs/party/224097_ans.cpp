// ans.cpp 19 Oct 17, 14:55:15 100 0 Judging completed in 2.526s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool arr[505];
vector<int>adj[505],f;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n,m,a,b,ans=0;
    cin>>n>>m;
    arr[1]=1;
    for(int x=0;x<m;x++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int x=0;x<adj[1].size();x++){
        if(arr[adj[1][x]]==false){
            ans++;
            arr[adj[1][x]]=true;
            f.push_back(adj[1][x]);
        }
    }
    for(int x=0;x<f.size();x++){
        for(int y=0;y<adj[f[x]].size();y++){
        	if(arr[adj[f[x]][y]]==false){
        		ans++;
        		arr[adj[f[x]][y]]=true;
        	}
        }
    }
    cout<<ans;
    return 0;
}