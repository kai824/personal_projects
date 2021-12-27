// ans.cpp 8 Nov 19, 11:05:08 22 0.08 Judging completed in 4.208s on AWS Oregon.
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
    int n,a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
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