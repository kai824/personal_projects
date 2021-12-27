// ans.cpp 29 Mar 17, 19:52:37 100 0.14 Judging completed in 4.168s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b,maxi=-3;
    bool meow=false;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>a;
        if(a>maxi){
            maxi=a;
            b=x;
            meow=false;
        }else if(a==maxi){
            meow=true;
        }
    }
    if(meow){
        cout<<"MMMMMEEEEOOOOOWWWW!!!!!\n";
    }else{
        cout<<b<<'\n';
    }
    return 0;
}