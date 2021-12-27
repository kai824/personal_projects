// ans.cpp 16 Nov 19, 08:43:08 0 0.1 Judging completed in 3.898s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
map<int,int> ft;

inline int ls(int x){
    return x & (-x);
}
void update(int x){
    for(;x<=500000000;x+=ls(x)){
        if(ft.find(x)==ft.end())ft[x]=1;
        else ft[x]++;
    }
}
int query(int x){
    int ans=0;
    for(;x;x-=ls(x)){
        if(ft.find(x)!=ft.end())ans+=ft[x];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    long long ans=0;
    cin>>n;
    pair<int,int> arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x].first>>arr[x].second;
    }
	cout<<'\n';
    sort(arr,arr+n);
    for(int x=n-1;x>=0;x--){
        ans+=query(arr[x].second);
        update(arr[x].second);
		cout<<arr[x].first<<' '<<arr[x].second<<' '<<ans<<'\n';
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