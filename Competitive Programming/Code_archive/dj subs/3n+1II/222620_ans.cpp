// ans.cpp 15 Oct 17, 11:32:07 80 0 Judging completed in 4.208s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    for(int x=1;x<b;x++){
        if(a==1){
            //cout<<-1;
            return 0;
        }
        if(a%2==0){
            a/=2;
        }else{
            a*=3;
            a++;
        }
    }
    cout<<a;
    return 0;
}