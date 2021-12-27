// ans.cpp 12 Nov 16, 15:50:25 0 1.59 Judging completed in 6.183s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,max_ans=0,cur=0,c,pc,d,pd;
    string b,pb="";
    cin>>a;
    for(int e=0;e<a;e=e+1){
        cin>>b>>c;
        if(c==1){
            cin>>d;
            if((e==0)||((pb==b)&&(pc==c)&&(pd==d))) cur=cur+1;
            else cur=1;
            pb=b;
            pc=c;
            pd=d;
            if(max_ans<cur) max_ans=cur;
        }else{
            cout<<max_ans;
        }
    }
    return 0;
}