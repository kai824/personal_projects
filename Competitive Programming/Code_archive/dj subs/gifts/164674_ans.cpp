// ans.cpp 23 Nov 16, 18:02:35 0 0.27 Judging completed in 7.15s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> gifts,history;
    int a,b,c;
    cin>>a>>b;
    for(int d=0;d<a;d++){
        cin>>c;
        gifts.push_back(c);
    }
    //c is now used as the iterator of the last one that was added
    c=0;
    for(int d=0;d<a;d++){
        if(d==0)history.push_back(gifts[d]);
        if(d>b){
          if(d-c>b){
            history.push_back(history[c]+gifts[d]);
            c=d;
          }else{
            if(history[d-b-1]+gifts[d]>history[d-1]){
              c=d;
              history.push_back(history[d-b-1]+gifts[d]);
            }else{
              history.push_back(history[d-1]);
            }
          }
        }else{
          if(gifts[d]>gifts[c]){
            c=d;
            history.push_back(gifts[d]);
          }
        }
    }
    cout<<history.back();
    return 0;
}