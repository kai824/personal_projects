// ans.cpp 13 Nov 18, 23:39:57 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#pragma O3
typedef long long ll;
inline ll convert(vector<ll> a){
	ll ans=0;
	for(int x=a.size()-1;x>=0;x--){
		ans*=10;
		ans+=a[x];
	}
	return ans;
}
bool flag=0;

inline char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}
ll powers[15]={
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000
};
//powers of 10 for O(1) calculation
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> start;
	queue<pair<ll,pair<ll,ll> > >bfs;
	unordered_map<ll,ll> m[11];
	//permutation, distance from ideal
	bool sorted;
	ll tc,n,a,ans;
	ll tmp,start_ll,d1,d2;
	pair<ll,ll> arr[10];//value, it in original
	tc=get();
	//cout<<"started\n";
	for(int x=1;x<=10;x++){
		start.clear();
		while(!bfs.empty()){
			bfs.pop();
		}
		for(int y=0;y<x;y++){
			start.push_back(y);
		}
		start_ll=convert(start);
		bfs.push(make_pair(start_ll,make_pair(0,0)));
		m[x][start_ll]=0;
		while(!bfs.empty()){
			//cout<<"L\n";
			for(int y=2;y<=x;y++){
				if(y==bfs.front().second.second)continue;
				start_ll=(bfs.front().first);
				for(int z=0;z<y;z++){
					if(z>=y-1-z)break;
					d1=(start_ll%powers[z+1])/powers[z];
					d2=(start_ll%powers[y-1-z+1])/powers[y-1-z];
					start_ll-=d1*powers[z];
					start_ll+=d2*powers[z];
					start_ll-=d2*powers[y-1-z];
					start_ll+=d1*powers[y-1-z];
				}
				if(bfs.front().second.first+1>5)break;
				tmp=start_ll;
				if(m[x].find(tmp)==m[x].end()){
					m[x][tmp]=bfs.front().second.first+1;
					bfs.push(make_pair(start_ll, make_pair(bfs.front().second.first+1,y)  ));
				}
			}
			bfs.pop();
		}
		//cout<<x<<'\n';
	}
	//cout<<"ready\n";
	while(tc--){
		m[0].clear();
		while(!bfs.empty()){
			bfs.pop();
		}
		start.clear();
		n=get();
		for(int x=n-1;x>=0;x--){
			arr[x].first=get();
			arr[x].second=x;
		}
		for(int x=0;x<n;x++){
			start.push_back(arr[x].first);
		}
		sort(arr,arr+n);
		for(int x=0;x<n;x++){
			start[arr[x].second]=x;
		}
		ans=11;
		start_ll=convert(start);
		m[0][start]=0;
		bfs.push(make_pair(start_ll,make_pair(0,0)));
		while(!bfs.empty()){
		    tmp=(bfs.front().first);
			if(m[n].find(tmp)!=m[n].end()){//exists...
				ans=(m[n][tmp]+bfs.front().second.first);
				break;
			}
			for(int y=2;y<=n;y++){
				if(y==bfs.front().second.second)continue;
				start_ll=bfs.front().first;
				for(int z=0;z<y;z++){
					if(z>=y-1-z)break;
					d1=(start_ll%powers[z+1])/powers[z];
					d2=(start_ll%powers[y-1-z+1])/powers[y-1-z];
					start_ll-=d1*powers[z];
					start_ll+=d2*powers[z];
					start_ll-=d2*powers[y-1-z];
					start_ll+=d1*powers[y-1-z];
				}
				if(bfs.front().second.first+1>5)break;
				if(m[0].find(start)==m[0].end()){
					cout<<"k\n";
					m[0][start]=bfs.front().second.first+1;
					bfs.push(make_pair(start_ll, make_pair(bfs.front().second.first+1,y)  ));
				}
			}
			bfs.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}