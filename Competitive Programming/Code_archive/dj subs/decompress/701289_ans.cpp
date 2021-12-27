// ans.cpp 16 Feb 20, 22:45:45 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[300005];
struct node{
    node *l,*r;
    int s,e,v;
    new node(int ss,int ee){
        s=ss;e=ee;
        if(s==e){
            v=arr[s];
            l=r=NULL;
        }else{
            l=new node(s,(s+e)/2);
            r=new node((s+e)/2+1,e);
            v=min(l->v,r->v);
        }
    }
    int query(int a,int b){
        if(a<=s && e<=b){
            return v;
        }
        int ans=INT_MAX;
        if(a<=(s+e)/2){
            ans=min(ans,l->query(a,b));
        }
        if((s+e)/2<b){
            ans=min(ans,r->query(a,b));
        }
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,p1,p2;
    cin>>n>>k;
    for(int x=1;x<=n-k+1;x++){
        cin>>arr[x];
    }
    p2=1;
    p1=p2-k+1;
    root=new node(1,n-k+1);
    for(int x=1;x<=n;x++){
        cout<<root->query(max(p1,1),min(p2,n-k+1));
        if(x<n)cout<<' ';
        p1++;p2++;
    }
    return 0;
}