#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second
#define cbr cerr<<"hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ll(x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x,y) (lower_bound(all(x),y)-x.begin())
#define ubd(x,y) (upper_bound(all(x),y)-x.begin())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return rng() % (y+1-x) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }

using ll=long long;
using ld=long double;
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
using pi=pair<ll,ll>; using spi=pair<ll,pi>; using dpi=pair<pi,pi>;

#define LLINF ((long long)1e18)
#define INF int(1e9+1e6)
#define MAXN (200006)
ll n,m,r,c;
pi A[MAXN], L[MAXN];
vector<vector<ll>> dist;
int main() {
	FAST
	cin>>n>>m>>r>>c;assert(1<=r*c&&r*c<=1e6);
	FOR(i,1,n) { cin>>A[i].f>>A[i].s; assert(A[i].f<=A[i].s&&0<=A[i].f&&A[i].s<=r+c-2); }
	FOR(i,1,m) { cin>>L[i].f>>L[i].s; assert(1<=L[i].f&&L[i].f<=r&&1<=L[i].s&&L[i].s<=c); }
	dist.resize(r+1, vector<ll>(c+1, -1));
	queue<pi> q;
	FOR(i,1,m) dist[L[i].f][L[i].s]=0, q.emplace(L[i]);
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};
	while(q.size()) {
		ll x=q.front().f, y=q.front().s;
		q.pop();
		FOR(i,0,3) {
			ll nx=x+dx[i], ny=y+dy[i];
			if(nx<1||ny<1||nx>r||ny>c||dist[nx][ny]!=-1) continue;
			dist[nx][ny]=dist[x][y]+1;
			q.emplace(nx,ny);
		}
	}
	deque<ll> v;
	FOR(i,1,r) FOR(j,1,c) {
		assert(~dist[i][j]);
		v.eb(dist[i][j]);
	}
	sort(all(v));
	sort(A+1, A+n+1);
	ll ans=0;
	FOR(i,1,n) {
		while(v.size()&&v[0]<A[i].f)v.pop_front();
		if(v.empty())break;
		if(v[0]<=A[i].s) v.pop_front(), ++ ans;
	}
	cout<<ans<<'\n';
}
/*
7 1 1 8
1 1
2 2
3 3
1 7
2 6
3 5
4 4
1 1

7
*/
