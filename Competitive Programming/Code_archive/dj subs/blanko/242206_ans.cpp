// ans.cpp 5 Nov 17, 09:57:44 0 0.62 Judging completed in 6.933s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<int,int> pii;
string arr;
ll n;
ll st[23][5000001];//sparse table...

ll ipow(ll b){
    return(1<<b);
}

void init(){
    ll b=ceil(log2(n)),ppow=2;
    for(ll x=0;x<n;x++){
        st[0][x]=x;
    }
    for(ll x=1;ppow<=n;x++){
        for(ll y=0;y+ppow-1<n;y++){
            if(arr[st[x-1][y]]-'0'<=arr[st[x-1][y+ppow/2]]-'0'){
                st[x][y]=st[x-1][y];
            }else{
                st[x][y]=st[x-1][y+ppow/2];
            }
        }
        ppow*=2;//stores 2^x
    }
}
pii query(ll a, ll b) {
	ll l,k;
    l=b-a+1;
    k=floor(log2(l));
    if(arr[st[k][a]]-'0'<=arr[st[k][a+l-ipow(k)]]-'0'){
        return(make_pair(arr[st[k][a]]-'0',st[k][a]));
    }else{
        return(make_pair(arr[st[k][a+l-ipow(k)]]-'0',st[k][a+l-ipow(k)]));
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int k,b;
    cin>>n>>k;
    string a;
    pii c;
    cin>>arr;
    init();
    b=0;
    for(int x=0;x<n-k;x++){
    	if(x==0){
    		c.first=2e9;
    		for(int y=0;y<=x+k;y++){
    			if(a[y]=='0' && n-k>1)continue;
    			if(a[y]-'0'<c.first){
    				c.first=a[y]-'0';
    				c.second=y;
    			}
    		}
    		cout<<c.first;
    		b=c.second+1;
    		continue;
    	}
        c=query(b,x+k);
        //if(x==0)cout<<c.first<<' '<<c.second<<'\n';
        cout<<c.first;
        b=c.second+1;
    }
    return 0;
}