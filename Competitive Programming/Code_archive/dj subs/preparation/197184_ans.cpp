// ans.cpp 6 Mar 17, 11:54:29 0 0 Judging completed in 5.698s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    uint64_t a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a<(b-a)){
        cout<<a;
        return 0;
    }
    if(a>(b-a)){
        cout<<((a-(b-a))/3)*2+(b-a);
        return 0;
    }
    if(a==b){
        if(a%2==0){
            cout<<(a/3)*2+1;
        }else{
            cout<<(a/3)*2;
        }
        return 0;
    }
    return 0;
}