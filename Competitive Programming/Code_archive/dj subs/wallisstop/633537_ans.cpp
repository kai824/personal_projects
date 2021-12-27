// ans.cpp 7 Dec 19, 12:40:19 100 0.62 Judging completed in 5.563s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int parent[100005],mini[100005],maxi[100005];//min and max height of current container


set<pair<pii,int> >::iterator it,it2;
map<int,set<pair<pii,int> > > vp;//vertical edge
map<int,set<pair<pii,int> > > hp;//horizontal edge
//index of edge, other coordinate(start,end), id

int getr(int x){
	if(parent[x]==-1)return x;
	parent[x]=getr(parent[x]);
	return parent[x];
}
inline void merge(int a,int b){
	a=getr(a);b=getr(b);
	if(a==b)return;
	parent[a]=b;
	mini[b]=min(mini[b],mini[a]);
	maxi[b]=max(maxi[b],maxi[a]);
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,h,w;
	int a,b,c,d,l,r;
	cin>>n>>h>>w;
	for(int x=0;x<n;x++){
		parent[x]=-1;
		cin>>a>>b>>c>>d;
		mini[x]=a;maxi[x]=c;
		//limits[x]=make_pair(make_pair(a,b),make_pair(c,d));
		if(vp.find(b)==vp.end())vp[b].insert(make_pair(make_pair(a,c),x));
		else{
			l=a;r=c;
			it=vp[b].lower_bound(make_pair(make_pair(a,0),0));
			//if(it!=vp[b].begin())it--;
			while(it!=vp[b].begin()){
				it2=it;it2--;
				if(l>it2->first.second)break;
				merge(x,it2->second);
				l=min(l,it2->first.first);
				r=max(r,it2->first.second);
				vp[b].erase(it2);
			}

			while(it!=vp[b].end() && it->first.first<=c){
				merge(x,it->second);
				l=min(l,it->first.first);
				r=max(r,it->first.second);
				it2=it;
				it++;
				vp[b].erase(it2);
			}
			vp[b].insert(make_pair(make_pair(l,r),getr(x)));
		}
		if(vp.find(d+1)==vp.end())vp[d+1].insert(make_pair(make_pair(a,c),x));
		else{
			l=a;r=c;
			it=vp[d+1].lower_bound(make_pair(make_pair(a,0),0));
			while(it!=vp[d+1].begin()){
				it2=it;it2--;
				if(l>it2->first.second)break;
				merge(x,it2->second);
				l=min(l,it2->first.first);
				r=max(r,it2->first.second);
				vp[d+1].erase(it2);
			}

			while(it!=vp[d+1].end() && it->first.first<=c){
				merge(x,it->second);
				l=min(l,it->first.first);
				r=max(r,it->first.second);
				it2=it;
				it++;
				vp[d+1].erase(it2);
			}
			vp[d+1].insert(make_pair(make_pair(l,r),getr(x)));
		}
		if(hp.find(a)==hp.end())hp[a].insert(make_pair(make_pair(b,d),x));
		else{
			l=b;r=d;
			it=hp[a].lower_bound(make_pair(make_pair(b,0),0));
			//if(it!=vp[b].begin())it--;
			while(it!=hp[a].begin()){
				it2=it;it2--;
				if(l>it2->first.second)break;
				merge(x,it2->second);
				l=min(l,it2->first.first);
				r=max(r,it2->first.second);
				hp[a].erase(it2);
			}

			while(it!=hp[a].end() && it->first.first<=d){
				merge(x,it->second);
				l=min(l,it->first.first);
				r=max(r,it->first.second);
				it2=it;
				it++;
				hp[a].erase(it2);
			}
			hp[a].insert(make_pair(make_pair(l,r),getr(x)));
		}
		if(hp.find(c+1)==hp.end())hp[c+1].insert(make_pair(make_pair(b,d),x));
		else{
			l=b;r=d;
			it=hp[c+1].lower_bound(make_pair(make_pair(b,0),0));
			//if(it!=vp[b].begin())it--;
			while(it!=hp[c+1].begin()){
				it2=it;it2--;
				if(l>it2->first.second)break;
				merge(x,it2->second);
				l=min(l,it2->first.first);
				r=max(r,it2->first.second);
				hp[c+1].erase(it2);
			}

			while(it!=hp[c+1].end() && it->first.first<=d){
				merge(x,it->second);
				l=min(l,it->first.first);
				r=max(r,it->first.second);
				it2=it;
				it++;
				hp[c+1].erase(it2);
			}
			hp[c+1].insert(make_pair(make_pair(l,r),getr(x)));
		}
	}
	for(int x=0;x<n;x++){
		if(mini[getr(x)]==1 && maxi[getr(x)]==h){
			cout<<"No";return 0;
		}/*else{
			cout<<mini[getr(x)]<<' '<<maxi[getr(x)]<<'\n';
		}*/
	}
	cout<<"Yes";
    return 0;
}

/*
5 7 7
1 1 4 2
3 3 3 3
2 4 2 7
3 7 7 7
5 2 6 5

8 12 16
10 13 12 14
7 4 9 13
3 14 8 15
5 3 11 3
1 8 5 9
1 11 2 14
6 4 6 7
2 2 3 7
*/