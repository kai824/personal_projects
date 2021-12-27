// ans.cpp 19 Nov 16, 11:39:54 0 0.3 Judging completed in 8.222s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,b,max_sum=0,cur_sum=0;
    cin>>n;
    for(int a=0;a<n;a++){
        cin>>b;
        if(cur_sum+(b*-1)>0){
            cur_sum=cur_sum+(b*-1);
        }else{
            cur_sum=0;
        }
        max_sum=max(cur_sum,max_sum);
    }
    cout<<max_sum*-1;
    return 0;
}