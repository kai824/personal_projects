// ans.cpp 22 Nov 16, 22:17:01 100 0.06 Judging completed in 2.831s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> row;
    vector<vector<int> > wall;
    int a,b,e;
    cin>>a>>b;
    for(int c=0;c<a;c++){
        row.clear();
        for(int d=0;d<b;d++){
            cin>>e;
            row.push_back(e);
        }
        wall.push_back(row);
    }
    //e is now used as the max
    for(int c=a-2;c>=0;c=c-1){
        for(int d=0;d<b;d++){
            e=wall[c+1][d];
            if(d!=0 && wall[c+1][d-1]>e) e=wall[c+1][d-1];
            if(b-d!=0 && wall[c+1][d+1]>e) e=wall[c+1][d+1];
            wall[c][d]=wall[c][d]+e;
        }
    }
    e=0;
    for(int d=0;d<b;d++){
        if(wall[0][d]>e)e=wall[0][d];
    }
    cout<<e;
    return 0;
}