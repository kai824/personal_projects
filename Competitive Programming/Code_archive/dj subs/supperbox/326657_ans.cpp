// ans.cpp 16 Feb 18, 15:38:29 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll wt[5005],val[5005],n;
ll K[505][505][505],arr[2][5005];
void knapSack(ll W, ll n,ll x){
    //x should be 0 to n-1, signifying that you start taking from item 1, item 2......
    ll i, w;
    //int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = x; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == x || w == 0)
                K[x][i][w] = 0;
            else if (wt[i - 1] <= w)
                K[x][i][w]
                        = max(val[i - 1] + K[x][i - 1][w - wt[i - 1]], K[x][i - 1][w]);
            else
                K[x][i][w] = K[x][i - 1][w];
        }
    }
 
    //return K[n][W];
}

void main2(){
    for(int x=1;x<=n;x++){
        cin>>wt[x]>>val[x];
    }
    int q,a,b,c;cin>>q;
    bool bit;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        bit=0;
        for(int x=a;x<=b;x++){
    		for(int y=0;y<=c;y++){
    			if(y>=wt[x]){
    				if(x!=a)arr[bit][y]=max(max(arr[!bit][y],arr[bit][y-1]),arr[!bit][y-wt[x]]+val[x]);
    				else arr[bit][y]=max(max(0,arr[bit][y-1]),val[x]);
    			}else{
    				if(x!=a)arr[bit][y]=max(arr[!bit][y],arr[bit][y-1]);
    				else arr[bit][y]=arr[bit][y-1];
    			}
    		}
    		bit=!bit;
    	}
    	cout<<arr[!bit][m]<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n>502){
        main2();return 0;
    }
    for(ll x=0;x<n;x++){
        cin>>wt[x]>>val[x];
    }
    for(ll x=0;x<n;x++){
        knapSack(500,n,x);
    }
    ll q,a,b,c;
    cin>>q;
    for(ll x=0;x<q;x++){
        cin>>a>>b>>c;
        cout<<K[a-1][b][c]<<'\n';
    }
    return 0;
}