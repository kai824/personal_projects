// ans.cpp 3 Dec 16, 15:21:29 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e,q,a,b,c;
    cin>>n>>e>>q;
    int adjMat[n][n],output[q];
    for(int x=0;x<n;x++){
        fill_n(adjMat[x],n,300);
    }
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjMat[a-1][b-1]=c;
        adjMat[b-1][a-1]=c;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
    			adjMat[i][j]=min(adjMat[i][j],adjMat[i][k]+adjMat[k][j];
    }}}
    for(int x=0;x<q;x++){
        cin>>a>>b;
        output[x]=adjMat[a-1][b-1];
    }
    for(int x=0;x<q;x++){
        cout<<output[x]<<endl;
    }
    return 0;
}