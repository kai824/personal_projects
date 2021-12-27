// ans.cpp 16 Nov 19, 20:00:13 90 0 Judging completed in 3.793s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[50005];

inline int ls(int x){
    return x & (-x);
}
void update(int x){
    for(;x<=50005;x+=ls(x)){
        ft[x]++;
    }
}
int query(int x){
    int ans=0;
    for(;x;x-=ls(x)){
        ans+=ft[x];
    }
    return ans;
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first==b.first)return a.second<b.second;
	return a.first>b.first;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,it,ans=0;
    cin>>n;
    pair<int,int> arr[n],dis[n];
    for(int x=0;x<n;x++){
        cin>>arr[x].first>>arr[x].second;
        dis[x].first=arr[x].second;
        dis[x].second=x;
    }
    sort(dis,dis+n);
    it=1;
    for(int x=0;x<n;x++){
        if(x>0 && dis[x].first!=dis[x].second)it++;
        arr[dis[x].second].second=it;
    }
	//cout<<'\n';
    sort(arr,arr+n,cmp);
    for(int x=0;x<n;x++){
		//cout<<arr[x].first<<' '<<arr[x].second<<' '<<query(arr[x].second)<<'\n';
        ans=max(ans,query(arr[x].second) );
        update(arr[x].second);
    }
    cout<<ans;
    return 0;
}

/*
8
1 3
2 5
5 8
3 6
2 5
3 8
3 6
3 8
*/