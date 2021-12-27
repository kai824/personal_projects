// ans.cpp 10 Aug 17, 17:57:29 70 0 Judging completed in 4.065s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,i,i1,x,y,c,sum,arr[10010],r,guest[10010],small;
int main() {
    
    cin>>c>>r;

    for (i1=0;i1<r;i1++){
      if(i1!=0){
        cin>>c;
      }
      
      for (i=0;i<c;i++){
        cin>>x>>y;
        if (y!=0){
          arr[y]++;
          if (guest[x]==0){
            n++;
            
          }
          else {
            arr[guest[x]]--;
            
          }
          guest[x]=y;
          
        }
        else {
          arr[guest[x]]--;
          n--;
          guest[x]=0;
          
        }
      }
      small=10010;
      for (auto it:arr){
        if (it<small&&it!=0){
          small=it;
        }
      }
      sum+=small;
      
    }
    cout<<sum<<endl;
    
}