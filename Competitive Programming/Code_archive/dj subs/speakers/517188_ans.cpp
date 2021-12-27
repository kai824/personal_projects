// ans.cpp 21 Apr 19, 14:25:37 0 0.02 Judging completed in 3.946s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,last_speaker=-1,speakers=0;
    cin>>n>>m;
    pair<int,int> peeps[n];
    for(int x=0;x<n;x++){
        cin>>peeps[x].first>>peeps[x].second;
        if(peeps[x].first<0)while(true){};
    }
    sort(peeps,peeps+n);
    for(int x=0;x<n;x++){
        if(last_speaker==-1 || last_speaker<peeps[x].first-peeps[x].second){
            //current person can't hear
            speakers++;
            last_speaker=peeps[x].first+peeps[x].second;
        }
    }
    cout<<speakers;
    return 0;
}