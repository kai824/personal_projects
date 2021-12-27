// ans.cpp 31 Oct 16, 21:37:58 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int vector_compare(vector<int>a,vector<int>b,int aa,int bb){
    int c=0;
    while(c<10000000000000000000000000){
        if (a[c]>b[c]) return 1;
        else if (a[c]<b[c]) return 2;
        else if ((a.size()<=(c+1))||(b.size()<=(c+1))){
            if (aa>=bb) return 1;
            else return 2;
        c=c+1;
        }
    }
}
int main() {
    int a,b,c,e;
    cin>>a;
    vector<vector<int>>d;
    vector<int>f;
    vector<int>g;
    for(b=0;b<a;b++){
        cin>>c;
        f.push_back(c);
        e=2;
        while(c!=1){
            if ((c/e)*e==c){
            d[b].push_back(e);
            c=c/e;
            }
            else e=e+1;
            if (c==1)break;
        }
    }
    while(a==a){
    c=1;
    for(b=0;b<(f.size()-1);b=b+1){
        if (vector_compare(d[b],d[b+1],f[b],f[b+1])==1){
            e=d[b];
            d[b]=d[b+1];
            d[b+1]=e;
            e=f[b];
            f[b]=f[b+1];
            f[b+1]=e;
            c=0;
        }
    }
    if (c==1) break;
}
    for(b=0;b<f.size();b=b+1){
        cout<<f[b]<<"\n";
    }
    return 0;
}