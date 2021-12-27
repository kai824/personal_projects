// ans.cpp 4 Dec 19, 16:52:35 32 0.1 Judging completed in 5.679s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[50005];
int getr(int x){
    if(parent[x]==-1)return x;
    parent[x]=getr(parent[x]);
    return parent[x];
}
inline void merge(int a,int b){
    a=getr(a);b=getr(b);
    if(a==b)return;
    parent[a]=b;
}
bool cmp(pair<pair<int,int>,pair<int,int> >a,pair<pair<int,int>,pair<int,int> >b){
    return a.first.second>b.first.second;
}
bool cmp2(pair<pair<int,pair<bool,int> >,pair<int,int> >a,pair<pair<int,pair<bool,int> >,pair<int,int> >b){
	return a>b;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q,a1,a2,o,c,it,pause;
    bool broke;
    cin>>n>>m;
    pair<pair<int,int>,pair<int,int> >edges[m];
    for(int x=0;x<m;x++){
        cin>>a1>>a2>>o>>c;
        edges[x].first=make_pair(o,c);
        edges[x].second=make_pair(a1,a2);
    }
    cin>>q;
    pair<pair<int,pair<bool,int> >,pair<int,int> > arr[q];//time,answer,it,the 2 nodes...
    for(int x=0;x<q;x++){
        arr[x].first.second.second=x;
        cin>>arr[x].second.first>>arr[x].second.second>>arr[x].first.first;
    }
    sort(arr,arr+q);
    
    sort(edges,edges+m);
    for(int x=0;x<n;x++){
        parent[x]=-1;
    }
    it=0;
    for(int x=0;x<q;x++){
        while(it<m && arr[x].first.first>=edges[it].first.first){
            merge(edges[it].second.first,edges[it].second.second);
            it++;
        }
        if(getr(arr[x].second.first)==getr(arr[x].second.second)){
            arr[x].first.second.first=true;
        }else arr[x].first.second.first=false;
        swap(arr[x].first.first,arr[x].first.second.second);
		//cout<<arr[x].first.second.second<<' '<<arr[x].first.second.first<<'\n';
		if(it>=m){
            pause=x+1;
            break;
        }
    }
    sort(edges,edges+m,cmp);it=0;
	sort(arr+pause,arr+q,cmp2);
    for(int x=0;x<n;x++){
        parent[x]=-1;
    }
    for(int x=pause;x<q;x++){
        broke=false;
        while(it<m && arr[x].first.first<=edges[it].first.second){
            merge(edges[it].second.first,edges[it].second.second);
			//cout<<"k "<<edges[it].first.second<<'\n';
            it++;
        }
        if(getr(arr[x].second.first)==getr(arr[x].second.second)){
            arr[x].first.second.first=true;
        }else arr[x].first.second.first=false;
        swap(arr[x].first.first,arr[x].first.second.second);
		//cout<<arr[x].first.second.second<<' '<<arr[x].first.second.first<<'\n';
    }
    sort(arr,arr+q);
    for(int x=0;x<q;x++){
        if(arr[x].first.first!=x){
            while(true){};
        }
        if(arr[x].first.second.first){
            cout<<"Y\n";
        }else{
            cout<<"N\n";
        }
    }
    return 0;
}