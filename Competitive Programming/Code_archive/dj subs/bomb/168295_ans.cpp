// ans.cpp 9 Dec 16, 20:23:36 0 0 Judging completed in 7.015s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool inter(int a,int b,int c,int d){
    if(c>d || a==b || c==d)return true;
    return false;
}
int main() {
    int a,ans;
    cin>>a;
    ans=a;
    int x[a],y[a];
    vector<int>adjlist[a];
    for(int b=0;b<a;b++){
        cin>>x[b];
        y[b]=x[b];
    }
    sort(x,x+a);
    for(int b=0;b<a;b++){
        for(int c=b+1;c<a;c++){
            if(inter(b,c,y[b],y[c])==true){
                adjlist[min(y[b],y[c])-1].push_back(max(y[b],y[c])-1);
            }
        }
    }
    bool parent[a];
    fill_n(parent,a,false);
    //UDFS begins!!!
    for(int b=0;b<a;b++){
        for(int c=0;c<adjlist[b].size();c++){
            parent[c]=true;
        }
    }
    for(int b=0;b<a;b++){
        if(parent[b])ans--;
    }
    cout<<max(ans,1);
    return 0;
}