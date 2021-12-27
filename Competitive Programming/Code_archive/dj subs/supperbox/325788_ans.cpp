// ans.cpp 13 Feb 18, 11:27:32 0 2.45 Judging completed in 14.421s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int wt[5005],val[5005],n;
int K[505][505][505];
void knapSack(int W, int n,int x){
    //x should be 0 to n-1, signifying that you start taking from item 1, item 2......
    int i, w;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>wt[x]>>val[x];
    }
    for(int x=0;x<n;x++){
        knapSack(500,n,x);
    }
    int q,a,b,c;
    cin>>q;
    for(int x=0;x<q;x++){
        cin>>a>>b>>c;
        cout<<K[a-1][b][c]<<'\n';
    }
    return 0;
}