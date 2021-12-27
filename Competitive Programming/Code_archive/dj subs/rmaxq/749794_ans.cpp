// ans.cpp 20 Jul 20, 22:16:05 0 0.01 Judging completed in 4.795s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[100005];

struct node{
    int s,e,v,lazy;
    node *l,*r;
    node(int ss,int ee){
        lazy=0;
        if(s==e){
            v=arr[s];
            l=r=NULL;
        }else{
            l=new node(s,(s+e)/2);
            r=new node((s+e)/2+1,e);
            v=max(l->v,r->v);
        }
    }
    void update(int a,int b,int c){
        if(a<=s && e<=b){
            v+=c;
            lazy+=c;
            return;
        }
        if(a<=(s+e)/2){
            l->update(a,b,c);
        }
        if((s+e)/2<b)r->update(a,b,c);
        v=lazy+max(l->v,r->v);
    }
    int query(int a,int b){
        if(a<=s && e<=b){
            return v;
        }
        int ans=INT_MIN;
        if(a<=(s+e)/2){
            ans=max(ans,l->query(a,b));
        }
        if((s+e)/2<b)ans=max(ans,r->query(a,b));
        return ans+lazy;
    }
} *root;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,a,b,c;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    root=new node(0,n-1);
    cin>>q;
    while(q--){
        cin>>a;
        if(a==0){
            cin>>a>>b;
            cout<<root->query(a,b)<<'\n';
        }else{
            cin>>a>>b>>c;
            root->update(a,b,c);//+c lazy propagation...
        }
    }
    return 0;
}