// ans.cpp 27 Feb 18, 23:01:12 100 0 Judging completed in 10.924s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int a[55],b[55],c[55],n,depth,max_depth=1,aa,bb,cc;
long long bitmask;//(1<<x) will mark the xth thing
inline bool fits(int x,int y){
    return(a[x]<=a[y] && b[x]<=b[y] && c[x]<=c[y]);
}
void dfs(int i){
    depth++;
    max_depth=max(max_depth,depth);
    for(int x=0;x<n;x++){
        if(((1<<x)&bitmask)==0 && fits(i,x)){
            bitmask+=(1<<x);
            dfs(x);
            bitmask-=(1<<x);
        }
    }
    depth--;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>aa>>bb>>cc;
        a[x]=min(aa,min(bb,cc));
        c[x]=max(aa,max(bb,cc));
        b[x]=aa+bb+cc-a[x]-c[x];
    }
    for(int x=0;x<n;x++){
        bitmask=(1<<x);
        depth=0;
        dfs(x);
        bitmask=0;
    }
    cout<<max_depth;
    return 0;
}