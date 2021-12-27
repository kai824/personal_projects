// ans.cpp 3 Dec 17, 16:35:15 100 0.13 Judging completed in 5.588s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnt[2000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> ans;
    vector<int>perms;//to generate permutations...
    int n,a;
    cin>>n;
    n=1<<n;
    cin>>a;//0
    for(int x=1;x<n;x++){
        cin>>a;
        if(cnt[a]==0){//not marked...
            ans.push_back(a);
            int b=perms.size();
            for(int y=0;y<b;y++){
                perms.push_back(perms[y]+a);
                cnt[perms[y]+a]++;//mark out stuff to expect...
            }
            perms.push_back(a);
        }else{
        	cnt[a]--;
        }
    }
    sort(ans.begin(),ans.end());
    for(int x=0;x<ans.size();x++){
        cout<<ans[x]<<'\n';
    }
    return 0;
}