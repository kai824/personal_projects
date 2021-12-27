// segmenttree.cpp 10 Dec 16, 15:20:08 0 0 Compilation failed on AWS Ireland.
#include "segmenttree.h"
using namespace std;
vector<int> tree;
int n;
/*I am a tree
Like you I breathe
But you need me
But I don't need you*/
int ipow(int a,int b){
    double c=a,d=b,e;
    e=pow(c,d);
    int ans=e;
    return ans;
}
void init(int N) {
    tree.assign(ipow(2,N),0);
    n=N;
}

void update2(int u){
    if(u>=1){
        tree[u]=min(tree[u*2],tree[u*2 +1]);
        u=u/2;
        update2(u);
    }
}

void update(int P, int V) {
    int a=tree.size()-(n-P);
    tree[a]=V;
    a=a/2;
    update2(a);
}

int query(int A, int B) {
    
}
