// ans.cpp 27 Nov 19, 11:44:43 100 0.14 Judging completed in 4.931s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    long long arr[n];
    vector<pair<long long,long long> > v;
    long long ans=0;
    //height, and the it
    //should be kept decreasing...
    for(int x=0;x<n;x++){
        cin>>arr[x];
        while(v.size()>0 && arr[x]>=v.back().first){
            if(v.size()>1)ans+=(min(arr[x],v[v.size()-2].first)-v.back().first)*(x-v[v.size()-2].second-1);
            v.pop_back();
        }
        v.push_back(make_pair(arr[x],x));
		/*for(int i=0;i<v.size();i++){
			cout<<v[i].first<<' ';
		}cout<<'\n';
		cout<<ans<<'\n';*/
    }
    cout<<ans;
    return 0;
}