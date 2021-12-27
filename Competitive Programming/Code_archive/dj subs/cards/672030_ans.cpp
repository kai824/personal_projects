// ans.cpp 2 Jan 20, 23:19:38 100 0.08 Judging completed in 4.391s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[500005];
int siz[500005];
bool used[500005];

int getr(int x){
    if(parent[x]==-1)return x;
    parent[x]=getr(parent[x]);
    return parent[x];
}
inline void merge(int a,int b){
    a=getr(a);b=getr(b);
    if(a==b)return;
    parent[a]=b;
    siz[b]+=siz[a];//since b is the new root
    siz[a]=0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,i;
    long long ans=0,a,b,tmp;
    cin>>n;
    pair<int,int> arr[n];
    for(int x=0;x<n;x++){
        arr[x].second=x;//iterator...
        cin>>arr[x].first;
        parent[x]=-1;
        siz[x]=1;
    }
    sort(arr,arr+n,greater<pair<int,int> >());
    for(int x=0;x<n;x++){
        i=arr[x].second;//the iterator...
        used[i]=true;
        a=b=0;
        if(i>0 && used[i-1]){
            a=siz[getr(i-1)];
        }
        if(i+1<n && used[i+1]){
            b=siz[getr(i+1)];
        }
		if(i>0 && used[i-1]){
            merge(i,i-1);
        }
        if(i+1<n && used[i+1]){
			merge(i,i+1);
        }
		//cout<<arr[x].first<<' '<<a<<' '<<b<<'\n';
        ans+=(a+1)*(b+1)*arr[x].first;
		//cout<<ans<<"\n\n";
    }
    cout<<ans;
    return 0;
}