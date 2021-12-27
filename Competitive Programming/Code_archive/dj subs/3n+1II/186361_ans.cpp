// ans.cpp 1 Feb 17, 19:23:21 100 0 Judging completed in 5.559s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    for(int x=1;x<b;x++){
        if(a==1){
            cout<<-1;
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