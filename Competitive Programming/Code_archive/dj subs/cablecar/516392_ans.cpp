// ans.cpp 19 Apr 19, 22:38:32 100 0.1 Judging completed in 4.059s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,ans=0;
    long long lo,hi,mid;
    vector<pair<int,int> > v;
    cin>>n>>a;
    v.push_back(make_pair(a,0));
    for(int x=1;x<n;x++){
        cin>>a;
        lo=0;hi=v.size()-1;
        while(lo<hi){
            mid=lo+hi-(lo+hi)/2;
                if(a>v[mid].first){
                    hi=mid-1;
                }else{
                    lo=mid;//v[mid].first>a=
                }
        }
		//cout<<x-v[lo].second<<'\t';
        ans=max(ans,x-v[lo].second);
        while(v.size()>0 && v.back().first<=a){
            v.pop_back();
        }
        v.push_back(make_pair(a,x));
		/*for(int y=0;y<v.size();y++){
			cout<<v[y].first<<' ';
		}cout<<'\n';*/
    }
    cout<<ans;
    return 0;
}