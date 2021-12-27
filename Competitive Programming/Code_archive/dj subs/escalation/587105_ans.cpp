// ans.cpp 8 Nov 19, 12:06:06 45 0.07 Judging completed in 4.618s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int> > adjl[100005];
ll limit,ans=0;
ll d[100005],aa[100005];
pair<int,int> arr[100005];

void main2(int n,int q){
	int maxi;
	ll lo,hi,mid,h1,h2,ans,base,a,b,l;
	for(int x=1;x<n;x++){
		cin>>a>>b>>l;
		arr[x-1].first=l;
	}
	h1=h2=0;
	for(int x=0;x<n;x++){
		if(x==0){
			cin>>base;continue;
		}
		cin>>arr[x-1].second;
		maxi=max(maxi,arr[x-1].second);
	}ans=maxi;
	sort(arr,arr+n-1);
	for(int x=0;x<n-1;x++){
		if(arr[x].second>=h1){
			h2=h1;h1=arr[x].second;
		}else if(arr[x].second>=h2){
			h2=arr[x].second;
		}
		ans=max(ans,h1+h2+base);
		aa[x]=ans;
	}

	for(int x=0;x<q;x++){
        cin>>a;
        if(a<arr[0].first){
            cout<<maxi<<"\n";
            continue;
        }
        lo=0;
        hi=n-2;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(arr[mid].first>a)hi=mid-1;
            else lo=mid;
        }
        cout<<aa[lo]<<'\n';
    }
}

bool vis[100005];

ll dfs(int node){
	vis[node]=true;
    ll maxi=0;
    for(int i=0;i<adjl[node].size();i++){
        if(adjl[node][i].second>limit)continue;
		if(vis[adjl[node][i].first])continue;
        maxi=max(maxi,dfs(adjl[node][i].first));
    }
	vis[node]=false;
    return maxi+d[node];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,q,a,b,l,lo,hi,mid;
    cin>>n>>q;
	if(n>1005){
		main2(n,q);
		return 0;
	}
    pair<int,pair<int,int> > el[n-1];
    for(int x=1;x<n;x++){
        cin>>a>>b>>l;
        el[x-1]=make_pair(l,make_pair(a,b));
        adjl[a].push_back(make_pair(b,l));
        adjl[b].push_back(make_pair(a,l));
    }
    b=0;
    for(int x=0;x<n;x++){
        cin>>d[x+1];
        b=max(b,d[x+1]);
    }
	ans=b;
    sort(el,el+n-1);
    for(int x=0;x<n-1;x++){
        limit=el[x].first;
		vis[el[x].second.second]=true;
		l=dfs(el[x].second.first);
		vis[el[x].second.second]=false;
		vis[el[x].second.first]=true;
		l+=dfs(el[x].second.second);
		vis[el[x].second.first]=false;
        ans=max(ans,l);
        aa[x]=ans;
    }
    for(int x=0;x<q;x++){
        cin>>a;
        if(a<el[0].first){
            cout<<b<<"\n";
            continue;
        }
        lo=0;
        hi=n-2;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(el[mid].first>a)hi=mid-1;
            else lo=mid;
        }
        cout<<aa[lo]<<'\n';
    }
    return 0;
}

/*
5 4
1 2 4
2 3 2
3 4 3
4 5 6
1 3 3 1 5
*/