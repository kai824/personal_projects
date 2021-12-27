// ans.cpp 13 Dec 16, 18:38:12 100 0.01 Judging completed in 3.078s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int r,c;
char a[1005][1005];
int DFS(int x,int y){
    a[x][y]='x';
    if (x+1<r && a[x+1][y]=='*')DFS(x+1,y);
    if(y+1<c && a[x][y+1]=='*')DFS(x,y+1);
    if (x-1>=0 && a[x-1][y]=='*')DFS(x-1,y);
    if(y-1>=0 && a[x][y-1]=='*')DFS(x,y-1);
}
int main() {
    cin>>r>>c;
    for (int i=0;i<r;i++){
        char k[1001];
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    int ct=0;
    for (int i=0;i<r;i++){
        for (int p=0;p<c;p++){
            if (a[i][p]=='*'){
                ct=ct+1;
                DFS(i,p);
            }
        }
    }cout<<ct<<endl;
}