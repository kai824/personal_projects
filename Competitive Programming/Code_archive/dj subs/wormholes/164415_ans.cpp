// ans.cpp 21 Nov 16, 20:54:38 60 0 Judging completed in 4.714s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int w_find(vector<pair<int,int> > w,int c){
    pair<int,int> ans;
    ans.first=-1;
    for(int a=0;a<w.size();a++){
        if(w[a].second==c){
            if(ans.first==-1 || w[a].first<=ans.second){
                ans.first=a;
                ans.second=w[a].first;
            }
        }
    }return ans.first;
}
int main() {
    pair<int,int> wormhole;
    vector<pair<int,int> > wormholes;
    vector<int> history;
    int n,w,a,b,current=0;
    cin>>n;
    cin>>w;
    for(int c=0;c<w;c++){
        cin>>a>>b;
        wormhole.first=a;
        wormhole.second=b;
        wormholes.push_back(wormhole);
    }
    history.push_back(0);
    for(int c=1;c<n;c++){//c is the planet you are currently at
        a=w_find(wormholes,c);
        if(a!=-1){
            if(history[wormholes[a].first]+1<=current+1){
                current=history[wormholes[a].first]+1;
            }else{
                current=current+1;
            }
        }else{
            current=current+1;
        }
        history.push_back(current);
    }
    cout<<current;
    return 0;
}