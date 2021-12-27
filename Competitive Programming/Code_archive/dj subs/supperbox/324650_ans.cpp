// ans.cpp 10 Feb 18, 16:53:49 0 2 Judging completed in 8.502s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int c[10005],s[10005],a,b,x;//weight, value

int val(int id, int remW){
    if(remW==0)return 0;
    if(id==b+1)return 0;
    if(c[id]>remW){
        return(val(id+1,remW));
    }
    return max(val(id+1,remW),s[id]+val(id+1,remW-c[id]));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>s[i];//calories, satisfaction...
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>x;
        cout<<val(a,x)<<'\n';
    }
    return 0;
}