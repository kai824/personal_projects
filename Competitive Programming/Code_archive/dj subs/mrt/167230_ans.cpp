// ans.cpp 3 Dec 16, 15:46:02 0 0.15 Judging completed in 4.488s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e,q,a,b,c;
    cin>>n>>e>>q;
    int adjMat[n][n],output[q];
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x==y)adjMat[x][y]=0;
            else adjMat[x][y]=1000000000;
        }
    }
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjMat[a-1][b-1]=c;
        adjMat[b-1][a-1]=c;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
    			adjMat[i][j]=min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
    }}}
    for(int x=0;x<q;x++){
        cin>>a>>b;
        if(a==b) output[x]=0;
        else output[x]=adjMat[a-1][b-1];
    }
    for(int x=0;x<q;x++){
        if(output[x]<1000000000)cout<<output[x]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}