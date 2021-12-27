// ans.cpp 1 Feb 17, 20:45:53 0 0.01 Judging completed in 2.47s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a,b;
    cin>>n>>m;
    bool arr[n];
    memset(arr,false,sizeof(arr));
    vector<int> c[n+1];//1-indexed.
    for(int x=0;x<m;x++){
        cin>>a>>b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    deque<int> bfs,bfs2;
    bfs.push_back(1);
    for(int x=0;x<c[1].size();x++){
        bfs.push_back(c[1][x]);
        arr[c[1][x]-1]=true;
    }
    bfs.pop_front();
    a=bfs.size();
    for(int x=0;x<a;x++){
        for(int y=0;y<c[bfs[x]].size();y++){
            arr[c[bfs[x]][x]-1]=true;
        }
    }
    a=0;
    for(int x=1;x<n;x++){
    	if(arr[x])a++;
    }
    cout<<a;
    return 0;
}