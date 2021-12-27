// ans.cpp 21 Sep 17, 13:22:39 100 0.47 Judging completed in 11.136s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,cur=1;//cur tells us the next number to "input"
    cin>>n;
    pair<int,int>coords=make_pair(0,0);//horizontal, vertical
    int ws[n][n];//weirdsquare
    bool ur=true;//up-right. Denotes direction(down-left when false)
    while(cur<=n*n){
        ws[coords.first][coords.second]=cur;
        if(ur){
            coords.first++;
            coords.second--;
            if(coords.second<0){
                ur=false;
                if(coords.first<n){
                    coords.second=0;
                }else{
                    coords.first--;
                    coords.second=1;
                }
            }
            if(coords.first>=n){
                ur=false;
                coords.first--;
                coords.second+=2;
            }
        }else{
            coords.first--;
            coords.second++;
            if(coords.second>=n){
                ur=true;
                coords.second--;
                coords.first+=2;
            }
            if(coords.first<0){
                ur=true;
                coords.first++;
            }
        }
        cur++;
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cout<<ws[y][x];
            if(y+1<n)cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}