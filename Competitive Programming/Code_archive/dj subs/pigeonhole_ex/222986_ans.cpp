// ans.cpp 17 Oct 17, 10:52:02 70 0.62 Judging completed in 4.277s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
struct node {
    int s, e, m, v;
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
void init(int N){
    root = new node(1,N);
}
int query1(int a, int b, node* x) {
    if (a > x->e || b < x->s) return -1;
    if (x->s >= a && x->e <= b) return x->v;
    /*ll v1 = 0, v2 = 0;
    if (x->l != nullptr)*/ ll v1 = query1(a, b, x->l);
    /*if (x->r != nullptr)*/ ll v2 = query1(a, b, x->r);
    return max(v1, v2);
}
void update1(int p, node* x, int v) {
    if (p > x->e || p < x->s) return;
    if (p == x->s && p == x->e) {x->v = v; return;}
    /*if (x->l == nullptr) x->l = new node(x->s, x->m);
    if (x->r == nullptr) x->r = new node(x->m+1, x->e);*/
    update1(p, x->l, v);
    update1(p, x->r, v);
    x->v = max(x->l->v, x->r->v);
    return;
}
void update(int p, int v) {
    update1(p, root, v);
    return;
}
int query(int a, int b) {
    return query1(a, b, root);
}
int arr[2000005];
int n,h,a,b,c=0;
void m2(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if(a==0)arr[b%h]--;
        else arr[b%h]++;
        c=-1;
        for(int x=0;x<h;x++){
            c=max(c,arr[x]);
        }
        cout<<c<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>h;
    if(n+h<2000){
        m2();return 0;
    }
    init(h);
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if(a==0)arr[b%h]--;
        else arr[b%h]++;
        update(b%h,arr[b%h]);
        cout<<query(0,h-1)<<'\n';
    }
    return 0;
}