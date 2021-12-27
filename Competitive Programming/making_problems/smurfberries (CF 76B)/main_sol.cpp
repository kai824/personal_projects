#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,A,B;
int arr[100005];
int brr[100005];
int taken[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);

	memset(taken,63,sizeof(taken));

	cin>>n>>m>>A>>B;

	rep(x,0,n) cin>>arr[x];

	brr[0]=-1e9;
	brr[m+1]=1e9;
	rep(x,1,m+1) cin>>brr[x];
	m+=2;

	int idx=-1;
	int ans=0;

	rep(x,0,n){
		while (idx!=m-1 && brr[idx+1]<=arr[x]) idx++;

		if (arr[x]-brr[idx]==brr[idx+1]-arr[x]){
			if (taken[idx]==arr[x]-brr[idx] || taken[idx]>1e9){
				ans++;
				taken[idx]=arr[x]-brr[idx];
			}
			else if (taken[idx+1]>=brr[idx+1]-arr[x]){
				if (taken[idx+1]==brr[idx+1]-arr[x] || taken[idx+1]>1e9) ans++;
				taken[idx+1]=brr[idx+1]-arr[x];
			}
		}
		else if (arr[x]-brr[idx]<brr[idx+1]-arr[x]){
			if (taken[idx]>=arr[x]-brr[idx]){
				if (taken[idx]==arr[x]-brr[idx] || taken[idx]>1e9) ans++;
				taken[idx]=arr[x]-brr[idx];
			}
		}
		else{
			if (taken[idx+1]>=brr[idx+1]-arr[x]){
				if (taken[idx+1]==brr[idx+1]-arr[x] || taken[idx+1]>1e9) ans++;
				taken[idx+1]=brr[idx+1]-arr[x];
			}
		}
	}

	//rep(x,0,m) cout<<taken[x]<<" "; cout<<endl;

	cout<<n-ans<<endl;
}