// ans.cpp 4 Feb 19, 15:34:26 100 0.24 Judging completed in 3.498s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2000][2000],task[2000];//number of points for each task
pair<int,pair<int,int> > pts[2000];
//score, number of tasks, then id
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,t,p;
    cin>>n>>t>>p;
    p--;
    for(int x=0;x<n;x++){
        for(int y=0;y<t;y++){
            cin>>arr[x][y];//contestant id, task number
            if(arr[x][y]==0)task[y]++;
        }
        pts[x]={0,{0,n-x} };
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<t;y++){
            if(arr[x][y]==1){
                pts[x].second.first++;
                pts[x].first+=task[y];
            }
        }
    }
    sort(pts,pts+n,greater<pair<int,pair<int,int> > >());
    for(int x=0;x<n;x++){
        if(pts[x].second.second==n-p){
            cout<<pts[x].first<<' '<<x+1;
            return 0;
        }
    }
    return 0;
}