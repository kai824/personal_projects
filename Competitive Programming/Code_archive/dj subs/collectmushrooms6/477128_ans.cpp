// ans.cpp 13 Jan 19, 22:05:55 100 0.02 Judging completed in 3.7s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    int r,c,i,x,y,n,d,k,i1,sum=0;
    cin>>r>>c>>d>>k;
    int arr[r+2][c+2],ps[r+2][c+2],diff[r+2][c+2];
    char ch;
    for (i=0;i<=r+1;i++){
      for (i1=0;i1<=c+1;i1++){
        ps[i][i1]=0;
        diff[i][i1]=0;
      }
    }
    for (i=1;i<=r;i++){
      for (i1=1;i1<=c;i1++){
        cin>>ch;
        if (ch=='.')arr[i][i1]=0;
        else if (ch=='M')arr[i][i1]=1;
        else if (ch=='S'){
          arr[i][i1]=2;
          diff[max(1,i-d)][max(1,i1-d)]+=1;
          diff[max(1,i-d)][min(c,i1+d)+1]-=1;
          diff[min(r,i+d)+1][max(1,i1-d)]-=1;
          diff[min(r,i+d)+1][min(c,i1+d)+1]+=1;
        }
        
      }
    }
    
    for (i=1;i<=r;i++){
      for (i1=1;i1<=c;i1++){
        ps[i][i1]=ps[i][i1-1]+diff[i][i1];
      }
    }
    for (i=1;i<=r;i++){
      for (i1=1;i1<=c;i1++){
        ps[i][i1]+=ps[i-1][i1];
      }
    }
    for (i=1;i<=r;i++){
      for (i1=1;i1<=c;i1++){
        if (arr[i][i1]==1){
          if (ps[i][i1]>=k)sum++;
          
        }
      }
    }
    cout<<sum<<'\n';
}