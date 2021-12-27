// ans.cpp 9 Dec 16, 16:26:03 0 4.01 Judging completed in 13.742s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return(a.second>b.second);
}
int get_root(int a){
    if(parent[a]==-1)return a;
    else{
        parent[a]=get_root(parent[a]);
        return parent[a];
    }
}
void merge(int a,int b){
    parent[get_root(a)]=get_root(b);
}
bool checkifconnected(int a,int b){
    return(get_root(a-1)==get_root(b));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<pair<int,int>,int> > edge_list;
    int n,e,q,a,b,c;
    cin>>n>>e>>q;
    parent.assign(n,-1);
    int output[q],input[q];
    fill_n(output,q,INT_MAX);
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        edge_list.push_back(make_pair(make_pair(a,b),c));
    }
    sort(edge_list.begin(),edge_list.end(),cmp);
    for(int x=0;x<q;x++){
        cin>>a;
        input[x]=a;
    }
    for(int x=0;x<edge_list.size();x++){
        a=edge_list[x].second;
        merge(edge_list[x].first.second,edge_list[x].first.first);
        for(int y=0;y<q;y++){
            if(output[y]==INT_MAX && checkifconnected(1,input[y]))output[y]=a;
        }
    }
    for(int x=0;x<q;x++){
        cout<<output[x]<<'\n';
    }
    return 0;
}