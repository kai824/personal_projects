// ans.cpp 27 Nov 19, 11:26:36 100 0.24 Judging completed in 4.278s on AWS Oregon.
//template big scam, I thought it was function call...

#include<bits/stdc++.h>
using namespace std;

bool emerged[1000005];
int parent[1000005],h[1000005],cur;

int get_root(int x){
    if(parent[x]==-1)return x;
    parent[x]=get_root(parent[x]);
    return parent[x];
}

inline void merge(int a,int b){
    a=get_root(a);b=get_root(b);
    if(a==b)return;
    parent[a]=b;
}

inline bool exis(int x){
    if(x<0)return false;
    return emerged[x];
}

int GW(int n){
    pair<int,int> arr[n];
    int islands=0,ans=0;
    for(int x=0;x<n;x++){
        arr[x].first=h[x];
        arr[x].second=x;
        parent[x]=-1;
    }
    sort(arr,arr+n);
    for(int x=n-1;x>=0;x--){
        cur=arr[x].second;
        emerged[cur]=true;
        if(exis(cur-1) && exis(cur+1)){
            islands--;
        }else if((exis(cur-1) || exis(cur+1))==false){
            islands++;
        }
        if(exis(cur-1))merge(cur-1,cur);
        if(exis(cur+1))merge(cur+1,cur);
        if(x==0 || arr[x].first!=arr[x-1].first)ans=max(ans,islands);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
   int n;
   cin>>n;
   for(int x=0;x<n;x++){
       cin>>h[x];
   }
   cout<<GW(n);
}