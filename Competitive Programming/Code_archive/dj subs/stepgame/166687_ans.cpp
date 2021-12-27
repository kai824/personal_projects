// ans.cpp 2 Dec 16, 18:00:38 100 0.28 Judging completed in 4.788s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,b,max_sum=0,cur_sum=0,max_num;
    cin>>n;
    for(int a=0;a<n;a++){
        cin>>b;
        if(b*-1>max_num){
            max_num=b*-1;
        }else if(a==0){
          max_num=b*-1;
        }
        if(cur_sum+(b*-1)>0){
            cur_sum=cur_sum+(b*-1);
        }else{
            cur_sum=0;
        }
        max_sum=max(cur_sum,max_sum);
    }
    if(max_sum==0) cout<<max_num*-1;
    else cout<<max_sum*-1;
    return 0;
}