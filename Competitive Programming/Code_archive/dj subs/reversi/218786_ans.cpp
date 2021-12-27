// ans.cpp 13 Aug 17, 17:06:52 0 0 Judging completed in 4.503s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int xpos[8]={0,0,1,1,1,-1,-1,-1};
int ypos[8]={-1,1,-1,0,1,-1,0,1};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int a,ans=0,current,xx,yy,c,ax,ay,a2=0;
    cin>>a;
    string board[a];
    for(int x=0;x<a;x++){
        cin>>board[x];
    }
    for(int x=0;x<a;x++){
        for(int y=0;y<a;y++){
            if(board[x][y]=='P')a2++;
            if(board[x][y]!='.')continue;
            current=0;
            for(int z=0;z<8;z++){
            xx=x;yy=y;c=0;
            while(0<=xx && xx<a && 0<=yy && yy<a){
                xx+=xpos[z];yy+=ypos[z];
                if(board[xx][yy]=='J')c++;
                else if(board[xx][yy]=='P'){
                    current+=c;
                    break;
                }else break;
            }
            }
            if(current>ans){
                ax=x;
                ay=y;
                ans=current;
            }
        }
    }
    cout<<ans<<' '<<a2<<'\n';
    cout<<ans+1+a2;
    return 0;
}