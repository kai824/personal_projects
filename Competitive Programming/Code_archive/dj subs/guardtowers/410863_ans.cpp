// ans.cpp 12 Nov 18, 14:41:31 54 0.26 Judging completed in 3.341s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=0,removed;
    cin>>n;
    int h[n];
    vector<pair<int,int> > v;//height, stuff removed
    for(int x=0;x<n;x++){
        cin>>h[x];
    }
    v.push_back(make_pair(h[0],0));
    for(int x=1;x<n;x++){
        ans+=v.size();
		removed=0;
        while(v.size()>0 && v.back().first<h[x]){
			removed++;
			removed+=v.back().second;
			ans+=v.back().second;
            v.pop_back();
        }
        v.push_back(make_pair(h[x],removed));
    }
    cout<<ans;
    return 0;
}