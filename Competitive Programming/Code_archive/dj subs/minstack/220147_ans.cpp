// ans.cpp 8 Sep 17, 15:28:22 0 2.35 Judging completed in 15.27s on AWS Oregon.
#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;
typedef long long ll;
int n;
bool b;
struct node {
    int s, e, m, v;
    node *l, *r;
    node(ll _s, ll _e) : s(_s), e(_e), m((_s+_e)/2), v(INT_MAX) {
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
void update(int p, int v) {
    update1(p+1, root, v);
    return;
}
int p=1,p1=1;
void push(int X) {
	if(!b){
		init(3000005);
		b=true;
	}
	update(p1,X);
	p1++;
}

void pop() {
	update(p1-1,INT_MAX);
	p1--;
}

int top() {
	return(query(p1-1,p1-1));
}

int getMin() {
	return(query(p,p1-1));
}