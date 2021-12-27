// ans.cpp 19 Nov 16, 11:38:46 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,b,max_sum=0;,cur_sum=0;
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
    cout<<max_sum;
    return 0;
}