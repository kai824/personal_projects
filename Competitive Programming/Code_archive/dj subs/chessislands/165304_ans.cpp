// ans.cpp 26 Nov 16, 13:29:02 0 1 Judging completed in 7.832s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
static int n,e,b,c,ans[50000];
vector<int> mv(){
    vector<int> a;
    return a;
}

void process(vector<vector<int> > mp,int *areas,int current){
    for(int a=0;a<mp[current].size();a++){
        if(ans[current]==-1){
            if(ans[mp[current][a]]==0){
                ans[mp[current][a]]=1;
                c+=areas[mp[current][a]];
            process(mp,areas,mp[current][a]);}
        }else if(ans[current]==1){
            if(ans[mp[current][a]]==0){
                ans[mp[current][a]]=-1;
                b+=areas[mp[current][a]];
            process(mp,areas,mp[current][a]);}
        }
    }
}
int main() {
    vector<vector<int> > d;
    cin>>n>>e;
    int a[n],f[n];//a is the areas of the islands
    for(int z=0;z<n;z++){
        cin>>b;
        a[z]=b;
        d.push_back(mv());
        ans[z]=0;
    }
    for(int z=0;z<e;z++){
        cin>>b>>c;
        d[b-1].push_back(c-1);
        d[c-1].push_back(b-1);
    }
    ans[0]=-1;
    b=a[0];
    c=0;
    process(d,a,0);
    cout<<min(b,c);
    return 0;
}