// ans.cpp 1 Apr 17, 22:06:03 0 0.5 Judging completed in 4.074s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,s,sum,maxi,med;
    cin>>n>>s;
    int scores[s],ranks[n];
    vector<pair<pair<int,int>, pair<int,int> > > v;
    for(int x=0;x<n;x++){
        sum=0;
        maxi=-1;
        for(int y=0;y<s;y++){
            cin>>scores[y];
            sum+=scores[y];
            maxi=max(maxi,scores[y]);
        }
        sort(scores,scores+s);
        if(s%2==1)med=scores[s/2];
        else med=(scores[s/2]+scores[s/2-1])/2;
        v.push_back(make_pair(make_pair(sum,maxi),make_pair(med,x)));
    }
    sort(v.begin(),v.end());
    for(int x=0;x<v.size();x++){
        ranks[v[x].second.second]=v.size()-x;
    }
    for(int x=0;x<n;x++){
        cout<<ranks[x]<<'\n';
    }
    return 0;
}