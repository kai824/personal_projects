// ans.cpp 14 Nov 17, 17:58:26 0 1.88 Judging completed in 5.701s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h,w,n,ans=0,a,b;
    cin>>h>>w>>n;
    set<int> s[n];
    int arr[h][w];
    for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
            cin>>arr[x][y];
        }
    }
    for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
            if(x+1<h){
                a=arr[x][y];b=arr[x+1][y];
                if(s[a].find(b)==s[a].end()){
                	s[a].insert(b);
                	s[b].insert(a);
                }
            }
            if(y+1<w){
                a=arr[x][y];b=arr[x][y+1];
                if(s[a].find(b)==s[a].end()){
                	s[a].insert(b);
                	s[b].insert(a);
                }
            }
        }
    }
    for(int x=0;x<n;x++){
    	cout<<s[x].size()<<'\n';
    }
    return 0;
}