// ans.cpp 29 Oct 17, 21:05:23 46 1.07 Judging completed in 5.623s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll s, e, m, v;
    node *l, *r;
    node(ll _s, ll _e) : s(_s), e(_e), m((_s+_e)/2), v(0) {
        if (_s != _e) {
            l = new node(s, m);
            r = new node(m+1, e);
        }        
    }
    ~node() {
        delete l;
        delete r;
    }
} *root;
void init(ll N){
    root = new node(1,N);
}
ll query1(ll a, ll b, node* x) {
    if (a > x->e || b < x->s) return 2e9;
    if (x->s >= a && x->e <= b) return x->v;
    /*ll v1 = 0, v2 = 0;
    if (x->l != nullptr)*/ ll v1 = query1(a, b, x->l);
    /*if (x->r != nullptr)*/ ll v2 = query1(a, b, x->r);
    return min(v1, v2);
}
void update1(ll p, node* x, ll v) {
    if (p > x->e || p < x->s) return;
    if (p == x->s && p == x->e) {x->v = v; return;}
    /*if (x->l == nullptr) x->l = new node(x->s, x->m);
    if (x->r == nullptr) x->r = new node(x->m+1, x->e);*/
    update1(p, x->l, v);
    update1(p, x->r, v);
    x->v = min(x->l->v, x->r->v);
    return;
}
void update(ll p, ll v) {
    update1(p+1, root, v);
    return;
}
ll query(ll a, ll b) {
    return query1(a+1, b+1, root);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,lo,hi,mid,a,b,ans=0;
    cin>>n;
    init(n);
    ll arr[n];
    for(ll x=0;x<n;x++){
        cin>>arr[x];
        update(x,arr[x]);
    }
    for(ll x=0;x<n;x++){
        lo=0;hi=x;
        while(lo<hi){
        	mid=lo+hi;
            mid-=(lo+hi)/2;
            if(query(x-mid,x)==arr[x]/* && (mid==0 || query(x-mid,x-1)!=arr[x])*/){
                lo=mid;//mid is usable...
            }else{//mid is not usable...
                hi=mid-1;
            }
        }
        a=lo+1;
        
        lo=0;hi=n-x-1;
        while(lo<hi){
            mid=(lo+hi);
            mid-=(lo+hi)/2;
            if(query(x,x+mid)==arr[x] && (mid==0 || query(x+1,x+mid)!=arr[x])){
                lo=mid;//mid is usable...
            }else{//mid is not usable...
                hi=mid-1;
            }
        }
        b=lo+1;
        ans+=(a*b*arr[x]);
    }
    cout<<ans;
    return 0;
}