// ans.cpp 26 Nov 16, 14:32:18 0 0.05 Judging completed in 5.753s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> friendships;//describes friendships
    vector<double> costs;
    int a,b,ans,d;
    double e;
    cin>>a>>b;
    for(int c=0;c<a;c++){
        friendships.push_back(0);
    }
    for(int c=0;c<a;c++){
        cin>>e;
        costs.push_back(e);
    }
    cin>>d;
    for(int c=0;c<d;c++){
        cin>>a>>b;
        friendships[a-1]+=1;
        friendships[b-1]+=1;
    }
    ans=0;
    for(int c=0;c<a;c++){
        costs[c]=friendships[c]/(costs[c]);
        if(c==0 || costs[c]>costs[ans]) ans=c;
    }
    cout<<ans;
    return 0;
}