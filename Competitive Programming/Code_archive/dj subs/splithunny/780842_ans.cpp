// ans.cpp 11 Nov 20, 09:46:52 0 0 Judging completed in 3.207s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int r,c;
char a[1005][1005];
int DFS(int x,int y){
    a[x][y]='.';
    if (x+1<r && a[x+1][y]=='H')DFS(x+1,y);
    if(y+1<c && a[x][y+1]=='H')DFS(x,y+1);
    if (x-1>=0 && a[x-1][y]=='H')DFS(x-1,y);
    if(y-1>=0 && a[x][y-1]=='H')DFS(x,y-1);
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
            if (a[i][p]=='H'){
                ct=ct+1;
                DFS(i,p);
            }
        }
    }cout<<"Oh, bother. There are "<<ct<<" pools of hunny."<<endl;
}