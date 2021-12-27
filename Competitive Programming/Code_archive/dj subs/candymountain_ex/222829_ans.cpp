// ans.cpp 16 Oct 17, 15:40:34 100 0.47 Judging completed in 4.342s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long n,k,i,i1,arr[100010]={4294967295},x,sum=0,sum1;
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
void main2(){
	init(n);
    for (i=1;i<=n;i++){
    	cin>>x;
    	if (i<=k){
    		arr[i]=x;
    		update(i,x);
    	}
    	else {
    		sum=0;
    		update(i,4294967295);
    		update(i,max(query(i-k,i),x));
    	}
    }
    i=n+1;
    sum=0;
    update(i,4294967295);
    sum=query(i-k,i);
    if(k>n)cout<<"0"<<'\n';
    else cout<<sum<<'\n';
}
int main() {
    cin>>n>>k;
    if((n*k)>1000000000){
    	main2();
    	return 0;
    }
    for (i=1;i<=n;i++){
    	cin>>x;
    	if (i<=k){
    		arr[i]=x;
    		
    	}
    	else {
    		sum=0;
    		arr[i]=4294967295;
    		for (i1=i-k;i1<i;i1++){
    			sum=max(x,arr[i1]);
    			arr[i]=min(sum,arr[i]);
    		}
    	}
    }
    i=n+1;
    sum=0;
    arr[i]=4294967295;
    for (i1=i-k;i1<i;i1++){
    	arr[i]=min(arr[i1],arr[i]);
    }
    if (k>n)cout<<"0"<<endl;
    else cout<<arr[n+1]<<endl;
    return 0;
}