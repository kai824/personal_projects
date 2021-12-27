// ans.cpp 6 Sep 17, 21:41:12 0 0 Compilation failed on AWS Oregon.
#include "changemin.h"
using namespace std;
typedef int ll;
int n;
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
    if (a > x->e || b < x->s) return 2e9;
    if (x->s >= a && x->e <= b) return x->v;
    /*ll v1 = 0, v2 = 0;
    if (x->l != nullptr)*/ ll v1 = query1(a, b, x->l);
    /*if (x->r != nullptr)*/ ll v2 = query1(a, b, x->r);
    return min(v1, v2);
}
void update1(int p, node* x, int v) {
    if (p > x->e || p < x->s) return;
    if (p == x->s && p == x->e) {x->v = v; return;}
    /*if (x->l == nullptr) x->l = new node(x->s, x->m);
    if (x->r == nullptr) x->r = new node(x->m+1, x->e);*/
    update1(p, x->l, v);
    update1(p, x->r, v);
    x->v = min(x->l->v, x->r->v);
    return;
}
int query(int a, int b) {
    return query1(a+1, b+1, root);
}


void loadArray(int N, int A[]) {
     init(N);
     for(int x=0;x<N;x++){
         update(x,A[x]);
     }
     n=N
}

void update(int p, int v) {
    update1(p+1, root, v);
    return;
}

int findMin() {
    return query(0,n-1);
}