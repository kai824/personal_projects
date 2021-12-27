// ans.cpp 26 Jan 17, 09:22:28 100 0.02 Judging completed in 5.976s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int to_copy[1005],farm[1005][1005];
int main() {
    int h,w,n;
    cin>>h>>w>>n;
    memset(to_copy,-1,sizeof(to_copy));
    for(int x=0;x<h;x++){
        if(n>=w){
            copy(begin(to_copy),end(to_copy),begin(farm[x]));
            n-=w;
        }else{
            for(int y=0;y<n;y++){
                farm[x][y]=-1;
            }
            break;
        }
    }
    for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
            if(farm[x][y]==-1)cout<<'X';
            else cout<<'O';
        }
        cout<<endl;
    }
    return 0;
}