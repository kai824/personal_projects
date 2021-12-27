#include"bits/stdc++.h"
using namespace std;

int dd[105],cost[105],minc=INT_MAX;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k,a;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)cin>>dd[i];
    for(int i=0;i<k;i++){
        cin>>a;
        for(int j=0;j<m;j++){
            if((a%dd[j])==0)cost[j]++;
        }
    }
    for(int i=0;i<m;i++)minc=min(minc,cost[i]);
    for(int i=0;i<m;i++){
        if(cost[i]==minc)v.push_back(i);
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]+1;
        if(i+1<v.size())cout<<' ';
    }
    return 0;
}
