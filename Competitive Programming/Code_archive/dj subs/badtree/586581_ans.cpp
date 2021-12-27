// ans.cpp 8 Nov 19, 11:08:29 100 0.18 Judging completed in 4.349s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
set<int> ss;
set<int>::iterator it,it2;
long long depth[200005],ans,cur;
bool lc[200005];
bool rc[200005];
char taken;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,i=0;
    cin>>n;
    int arr[n];
    pair<int,int> arr2[n];//discretisation
    
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr2[x].first=arr[x];
        arr2[x].second=x;
    }
    sort(arr2,arr2+n);
    for(int x=0;x<n;x++){
        if(x>0 && arr[x]!=arr[x-1])i++;
        arr[arr2[x].second]=i;
    }
    for(int x=0;x<n;x++){
        a=arr[x];
        if(x>0){
            cur=INT_MAX;taken='n';
            it=it2=ss.lower_bound(a);
            if(it!=ss.end() && lc[*it]==false){
                cur=depth[*it];taken='l';
            }
            if(it!=ss.begin()){
                it2--;
                if(rc[*it2]==false && depth[*it2]<cur){
                    taken='r';
                    cur=depth[*it2];
                }
            }
            ans+=cur;
            if(taken=='l'){
                lc[*it]=true;
            }else if(taken=='r'){
                rc[*it2]=true;
            }else{
                //cout<<"-1\n";
            }
            depth[a]=cur+1;
        }else{
            depth[a]=1;
        }
        ss.insert(a);
    }
    cout<<ans;
    return 0;
}