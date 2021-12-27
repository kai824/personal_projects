// ans.cpp 27 Nov 19, 13:17:14 100 0.4 Judging completed in 4.934s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool emerged[1000005];
pair<int,pair<int,int> >arr[1000005];
int parent[1000005],n,m;

int get_root(int x){
    if(parent[x]==-1)return x;
    parent[x]=get_root(parent[x]);
    return parent[x];
}

inline bool merge(int a,int b){
    if(emerged[a]==false || emerged[b]==false)return false;
    a=get_root(a);b=get_root(b);
    if(a==b)return false;
    parent[a]=b;
    return true;
}

inline bool valid(int x,int y){
    return (0<=x && x<n && 0<=y && y<m);
}
inline int convert(int a,int b){
    return (m*a+b);
}
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    int a,b,c,d,islands=0,ans=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>c;
            arr[convert(x,y)]=make_pair(c,make_pair(x,y));
			parent[convert(x,y)]=-1;
        }
    }
    sort(arr,arr+(n*m));
    for(int x=(n*m)-1;x>=0;x--){
        c=convert(arr[x].second.first,arr[x].second.second);d=0;
        emerged[c]=true;
        for(int i=0;i<4;i++){
            a=arr[x].second.first+xx[i];b=arr[x].second.second+yy[i];
            if(valid(a,b) && merge(c,convert(a,b)))d++;
        }
        islands+=1-d;
        if(x==0 || arr[x].first!=arr[x-1].first){
            ans=max(ans,islands);
        }
    }
	cout<<ans;
    return 0;
}