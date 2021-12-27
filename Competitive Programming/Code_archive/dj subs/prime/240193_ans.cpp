// ans.cpp 4 Nov 17, 10:24:36 100 0 Judging completed in 2.403s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    if(a<2){
        cout<<"Not Prime";
        return 0;
    }
    for(int x=2;x<a;x++){
        if(x*x>a)break;
        if(a%x==0){
            cout<<"Not Prime";
            return 0;
        }
    }
    cout<<"Prime";
    return 0;
}