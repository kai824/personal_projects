// ans.cpp 19 Nov 16, 11:46:43 0 0.3 Judging completed in 6.282s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,b,max_sum=0,cur_sum=0,max_num=0;;
    cin>>n;
    for(int a=0;a<n;a++){
        cin>>b;
        if(b*-1>max_num){
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