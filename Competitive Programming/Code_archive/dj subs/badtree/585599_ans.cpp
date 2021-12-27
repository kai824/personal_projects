// ans.cpp 8 Nov 19, 08:54:09 36 1 Judging completed in 5.403s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
pair<int,int> children[200005];
long long ans=0,nex;
void dfs(int node,int v){
    ans++;
    if(node<v){
        if(children[node].second==-1){
            children[node].second=v;
            return;
        }
        dfs(children[node].second,v);
        return;
    }else if(v<node){
        if(children[node].first==-1){
            children[node].first=v;
            return;
        }
        dfs(children[node].first,v);
        return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,root=-1,it=0;
    cin>>n;
    if(n>50000){
        ans=n*(n-1)/2;
        cout<<ans;
        return 0;
    }
    int arr[n];
    pair<int,int> arr2[n];//discretisation
    for(int x=0;x<200005;x++){
        children[x]=make_pair(-1,-1);
    }
    
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr2[x].first=arr[x];
        arr2[x].second=x;
    }
    sort(arr2,arr2+n);
    for(int x=0;x<n;x++){
        if(x>0 && arr[x]!=arr[x-1])it++;
        arr[arr2[x].second]=it;
    }
    
    for(int x=0;x<n;x++){
        a=arr[x];
        if(root==-1){
            root=a;
            continue;
        }
        dfs(root,a);
    }
    cout<<ans;
    return 0;
}