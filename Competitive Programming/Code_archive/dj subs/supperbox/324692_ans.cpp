// ans.cpp 10 Feb 18, 17:02:07 0 2.08 Judging completed in 7.965s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int c[10005],s[10005],a,b,x;//weight, value
int knapsack[10005][2005];
int val(int id, int remW){
    if(remW==0)return 0;
    if(id>=b+1)return 0;
    if(c[id]>remW){
    if(knapsack[id][remW]==-1)knapsack[id][remW]=val(id+1,remW);
        return(knapsack[id][remW]);
    }
    if(knapsack[id][remW]==-1)knapsack[id][remW]=max(val(id+1,remW),s[id]+val(id+1,remW-c[id]));
    return knapsack[id][remW];
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>s[i];//calories, satisfaction...
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>x;
        for(int y=a;y<=b+3;y++){
            for(int z=0;z<2005;z++){
                knapsack[y][z]=-1;
            }
        }
        cout<<val(a,x)<<'\n';
    }
    return 0;
}