// ans.cpp 18 Nov 20, 10:19:13 0 1 Judging completed in 5.133s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int ft[100005],n;

int ls(int x){
    return x&(-x);
}
int query(int p){
    int sum=0;
    for(;p;p-=ls(p))sum+=ft[p];
    return sum;
}
void update(int p,int v){//increase array element at p, by v
    for(;p<=n;p+=ls(p) )ft[p]+=v;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int a,b,c,q;
    for(int i=1;i<=n;i++){
        cin>>a;
        update(i,a);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a;
        if(a==0){
            cin>>a>>b;
            cout<<query(b)-query(a-1)<<'\n';
        }else{
            cin>>a>>b>>c;
            update(a,c);
        }
    }
    return 0;
}