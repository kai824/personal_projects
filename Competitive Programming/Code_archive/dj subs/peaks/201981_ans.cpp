// ans.cpp 22 Mar 17, 20:56:15 0 0.29 Judging completed in 5.166s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,current/*current peak size*/=0,to_test,topush;
    cin>>n;
    vector<int> currentpeaks,currentpeaks2;
    for(int x=1;x<=n;x++){
        cin>>topush;
        currentpeaks.push_back(topush);
    }
    while(true){
        current++;
        for(int x=current;x<currentpeaks.size()-current;x++){
            if(currentpeaks[x-current]<currentpeaks[x] && currentpeaks[x+current]<currentpeaks[x]){
                currentpeaks2.push_back(currentpeaks[x]);
            }
        }
        if(currentpeaks2.size()==0){
            current--;
            break;
        }
        currentpeaks.clear();
        swap(currentpeaks,currentpeaks2);
    }
    cout<<current<<'\n';
    return 0;
}