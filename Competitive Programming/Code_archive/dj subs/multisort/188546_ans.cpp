// ans.cpp 7 Feb 17, 12:51:38 0 0 Judging completed in 2.476s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int> > nums;
    vector<int> to_use;
    int n,m,a;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>a;
            nums.push_back(to_use);
            nums[x].push_back(a);
        }sort(nums[x].begin(),nums[x].end());
    }
    sort(nums.begin(),nums.end());
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cout<<nums[x][y];
            if(y+1<m)cout<<' ';
        }cout<<endl;
    }
    return 0;
}