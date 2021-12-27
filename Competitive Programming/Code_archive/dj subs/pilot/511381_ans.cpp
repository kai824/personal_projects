// ans.cpp 31 Mar 19, 16:41:47 100 0.52 Judging completed in 5.742s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ans[1000005];
int mp[1000005],r[1000005];
long long val[1000005];
int get_root(int x){
	if(mp[x]==x) return x;
	else mp[x]=get_root(mp[x]);
	return mp[x];
}
inline bool check(int x,int y){
	return get_root(x)==get_root(y);
}
inline void combine(int x,int y){
    if (check(x,y))return;
	if(r[x]<r[y]){
	    val[get_root(y)]+=val[get_root(x)];//since it's the new root
	    mp[get_root(x)]=get_root(y);
	}else if(r[y]<r[x]){
	    val[get_root(x)]+=val[get_root(y)];
	    mp[get_root(y)]=get_root(x);
	}else {
	    val[get_root(y)]+=val[get_root(x)];
		mp[get_root(x)]=get_root(y);
		r[get_root(y)]+=1;
	}
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,cur_it=0,a;
	long long v;
    cin>>n>>q;
    pair<int,int> arr[n];//value, it
    for(int x=0;x<n;x++){
        cin>>arr[x].first;
        arr[x].second=x+1;
    }
    for(int x=0;x<=1000002;x++){
        val[x]=0;//number of connected stuff
        mp[x]=x;r[x]=1;
    }
    sort(arr,arr+n);
    ans[0]=0;
    for(int x=1;x<=1000002;x++){
        ans[x]=ans[x-1];
        while(cur_it<n && arr[cur_it].first<=x){
			val[arr[cur_it].second]=1;
            v=val[get_root(arr[cur_it].second-1)];
            ans[x]-=(v*(v+1))/2;
            v=val[get_root(arr[cur_it].second+1)];
            ans[x]-=(v*(v+1))/2;
            if(val[get_root(arr[cur_it].second-1)]>0)combine(arr[cur_it].second-1,arr[cur_it].second);
            if(val[get_root(arr[cur_it].second+1)]>0)combine(arr[cur_it].second,arr[cur_it].second+1);
            v=val[get_root(arr[cur_it].second)];
            ans[x]+=(v*(v+1))/2;
			cur_it++;
        }
		//if(x<=5)cout<<ans[x]<<' ';
    }//cout<<'\n';
    for(int x=0;x<q;x++){
        cin>>a;cout<<ans[a]<<'\n';
    }
    return 0;
}