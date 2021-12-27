// ans.cpp 26 Jun 17, 15:26:41 100 0.22 Judging completed in 6.421s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,trees[25];
vector<int> stuff;
//it as in iterator of next one to add, cur as in current sum
void process(int it,int cur){
    if(it==n){
        stuff.push_back(cur);
        return;
    }
    process(it+1,cur);
    process(it+1,cur+trees[it]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>trees[x];
    }
    process(0,0);
    sort(stuff.begin(),stuff.end());
    for(int x=0;x<stuff.size();x++){
    	cout<<stuff[x]<<'\n';
    }
    return 0;
}