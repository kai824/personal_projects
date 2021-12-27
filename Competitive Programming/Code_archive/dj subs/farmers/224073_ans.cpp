// ans.cpp 19 Oct 17, 14:05:06 56 0.26 Judging completed in 3.994s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,m;
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
    if (a > x->e || b < x->s) return 1%m;
    if (x->s >= a && x->e <= b) return (x->v)%m;
    /*ll v1 = 0, v2 = 0;
    if (x->l != nullptr)*/ ll v1 = query1(a, b, x->l);
    /*if (x->r != nullptr)*/ ll v2 = query1(a, b, x->r);
    return (v1*v2)%m;
}
void update1(ll p, node* x, ll v) {
    if (p > x->e || p < x->s) return;
    if (p == x->s && p == x->e) {x->v = v%m; return;}
    /*if (x->l == nullptr) x->l = new node(x->s, x->m);
    if (x->r == nullptr) x->r = new node(x->m+1, x->e);*/
    update1(p, x->l, v);
    update1(p, x->r, v);
    x->v = (x->l->v * x->r->v)%m;
    return;
}
void update(ll p, ll v){
    update1(p+1, root, v);
    return;
}
ll query(ll a, ll b) {
    return query1(a+1, b+1, root);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c;
    cin>>n>>q>>m;
    init(n);
    for(ll x=0;x<n;x++){
        cin>>a;
        update(x,a);
    }
    for(ll x=0;x<q;x++){
        cin>>a>>b>>c;
        if(a==0){
            cout<<query(b,c)<<'\n';
        }else{
            update(b,c);
        }
    }
    return 0;
}