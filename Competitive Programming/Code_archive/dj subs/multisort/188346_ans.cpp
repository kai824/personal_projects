// ans.cpp 5 Feb 17, 21:30:17 20 0 Judging completed in 3.434s on AWS Oregon.
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
        }
    }
    for(int x=0;x<n;x++){
        sort(nums[x].begin(),nums[x].end());
        for(int y=0;y<m;y++){
            cout<<nums[x][y];
            if(y+1<m)cout<<' ';
        }cout<<endl;
    }
    return 0;
}