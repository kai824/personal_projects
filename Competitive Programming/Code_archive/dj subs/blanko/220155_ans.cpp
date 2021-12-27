// ans.cpp 8 Sep 17, 22:00:54 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int int;
typedef pair<int,int> pii;
struct node {
    int s, e, m, v,it;//start, end, middle, value
    node *l, *r;
    node(ll _s, ll _e) : s(_s), e(_e), m((_s+_e)/2), v(0),it(s) {
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
pii query1(int a, int b, node* x) {
    if (a > x->e || b < x->s) return make_pair(2e9,-10);
    if (x->s >= a && x->e <= b) return make_pair(x->v,x->it);
    /*ll v1 = 0, v2 = 0;
    if (x->l != nullptr)*/ pii v1 = query1(a, b, x->l);
    /*if (x->r != nullptr)*/ pii v2 = query1(a, b, x->r);
    if(v1.first<=v2.first){
        return(v1);
    }else{
        return(v2);
    }
}
void update1(int p, node* x, int v) {
    if (p > x->e || p < x->s) return;
    if (p == x->s && p == x->e) {x->v = v; return;}
    /*if (x->l == nullptr) x->l = new node(x->s, x->m);
    if (x->r == nullptr) x->r = new node(x->m+1, x->e);*/
    update1(p, x->l, v);
    update1(p, x->r, v);
    //x->v = min(x->l->v, x->r->v);
    if(x->l->v <= x->r->v){
    	x->v=x->l->v;
    	x->it=x->l->it;
    }else{
    	x->v=x->r->v;
    	x->it=x->r->it;
    }
    return;
}
void update(int p, int v) {
    update1(p+1, root, v);
    return;
}
pii query(int a, int b) {
	//cout<<a<<' '<<b<<'\n';
    pii ans=query1(a+1, b+1, root);
    ans.second--;
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n,k,b;
    cin>>n>>k;
    string a;
    pii c;
    cin>>a;
    init(n);
    for(int x=0;x<n;x++){
        update(x,a[x]-'0');
    }
    b=0;
    for(int x=0;x<n-k;x++){
    	if(x==0){
    		c.first=2e9;
    		for(int y=0;y<x+k;y++){
    			if(a[y]=='0')continue;
    			if(a[y]-'0'<c.first){
    				c.first=a[y]-'0';
    				c.second=y;
    			}
    		}
    		cout<<c.first;
    		b=c.second+1;
    		continue;
    	}
        c=query(b,x+k);
        //if(x==0)cout<<c.first<<' '<<c.second<<'\n';
        cout<<c.first;
        b=c.second+1;
    }
    return 0;
}