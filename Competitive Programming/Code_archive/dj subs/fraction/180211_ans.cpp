// ans.cpp 12 Jan 17, 21:59:56 0 1 Judging completed in 7.271s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,c=2;
    cin>>a>>b;
    while(true){
        if(((c*2)>a)||((c*2)>b)) break;
        if((a%c==0)&&(b%c==0)){
            a=a/c;
            b=b/c;
        }
        else c=c+1;
    }
    cout<<a<<"/"<<b;
    return 0;
}